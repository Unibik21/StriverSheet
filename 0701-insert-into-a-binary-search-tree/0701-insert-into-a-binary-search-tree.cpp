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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root ;

        if(root==NULL)return new TreeNode(val);
        while(true){
            if(root->val < val && root->right){
                root=root->right;
            }
            else if(root->val >val && root->left){
                root= root->left;
            }
            else if(root->val < val){
                root->right = new TreeNode(val);
                return temp;
            }
            else if(root->val > val){
                root->left = new TreeNode(val);
                return temp;
            }
        }
    }
};