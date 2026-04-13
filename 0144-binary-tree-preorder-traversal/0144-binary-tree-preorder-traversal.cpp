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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>pre;
        TreeNode* curr = root;

        while(curr!=NULL){
            if(curr->left==NULL){
                pre.push_back(curr->val);
                curr= curr->right;
            }
            else{
                TreeNode* next = curr->left;
                while(next->right && next->right!=curr){
                    next=next->right;
                }
                if(next->right==NULL){
                    next->right = curr;
                    pre.push_back(curr->val);
                    curr= curr->left;
                }
                else{
                    next->right=NULL;
                    curr=curr->right;
                }
            }
        }

        return pre;
    }
};