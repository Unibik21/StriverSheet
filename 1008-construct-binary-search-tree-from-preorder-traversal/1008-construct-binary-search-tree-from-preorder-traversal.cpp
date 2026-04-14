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
    TreeNode* solve(int &i,int ub,vector<int>& preorder){
        if(i==preorder.size() || preorder[i]>ub)return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = solve(i,root->val,preorder);
        root->right = solve(i,ub,preorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i =0;
        return solve(i,INT_MAX,preorder);
    }
};