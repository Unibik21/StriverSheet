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
    void traversal(vector<int>&in,TreeNode* root,int &i){
        if(root==NULL)return;

        traversal(in,root->left,i);
        if(in[i]!=root->val){
            root->val = in[i];
        }
        i++;
        traversal(in,root->right,i);
    }
    void inorder(TreeNode* root,vector<int>&in){
        if(root==NULL)return;

        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    void recoverTree(TreeNode* root) {
        vector<int>in;
        inorder(root,in);
        sort(in.begin(),in.end());
        int i=0;
        traversal(in,root,i);
    }
};