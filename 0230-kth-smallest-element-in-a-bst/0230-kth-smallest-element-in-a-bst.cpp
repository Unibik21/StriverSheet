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
    int nodes(TreeNode* root){
        if(root==NULL)return 0;

        int left = nodes(root->left);
        int right = nodes(root->right);

        return 1+left+right;
    }
    int solve(TreeNode* root,int k){

        while(root!=NULL){
            int lh= nodes(root->left);
            if(lh==k-1)return root->val;
            else if(lh>k-1){
                root=root->left;
            }
            else{
                k=k-lh-1;
                root=root->right;
            }
        }

        return 0;

    }
    int kthSmallest(TreeNode* root, int k) {
        return solve(root,k);
    }
};