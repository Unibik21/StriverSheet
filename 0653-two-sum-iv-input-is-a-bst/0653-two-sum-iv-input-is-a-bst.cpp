/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    stack<TreeNode*>n;
    stack<TreeNode*>b;
    int next(){
        TreeNode* top = n.top();
        n.pop();
        if(top->right){
            TreeNode* rt = top->right;
            while(rt){
                n.push(rt);
                rt=rt->left;
            }
        }
        return top->val;
    }
    int before(){
        TreeNode* top = b.top();
        b.pop();
        if(top->left){
            TreeNode* lt = top->left;
            while(lt){
                b.push(lt);
                lt=lt->right;
            }
        }
        return top->val;
    }
    bool findTarget(TreeNode* root, int k) {
        TreeNode* temp1 = root;
        TreeNode* temp2 = root;

        while(temp1){
            n.push(temp1);
            temp1=temp1->left;
        }

        while(temp2){
            b.push(temp2);
            temp2=temp2->right;
        }
        int first = next();
        int sec = before();
        while(first<sec){
            int sum = first+sec;
            if(sum==k)return true;
            else if(sum>k) sec = before();
            else first = next();
        }
        return false;
    }
};