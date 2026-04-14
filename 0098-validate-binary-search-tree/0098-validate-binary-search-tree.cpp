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
    void inorder(vector<int>&ans,TreeNode* root){
        if(root==NULL)return;

        inorder(ans,root->left);
        ans.push_back(root->val);
        inorder(ans,root->right);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>in;
        inorder(in,root);

        for(int i=0;i<in.size()-1;i++){
            if(in[i]>=in[i+1])return false;
        }

        return true;
    }
};