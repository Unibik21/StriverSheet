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
    void insert(TreeNode* root,int val){
        while(true){
            if(root->val>val){
                if(!root->left){
                    root->left = new TreeNode(val);
                    return;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(!root->right){
                    root->right = new TreeNode(val);
                    return;
                }
                else{
                    root=root->right;
                }
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)return new TreeNode(val);
        insert(root,val);
        return root;
    }
};