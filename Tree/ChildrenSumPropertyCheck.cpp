#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int v){
            val=v;
            left=NULL;
            right = NULL;
        }
};

void solve(TreeNode* root){
    if(root==NULL)return;
    
    int l = (root->left==NULL)?0:root->left->val;
    int r = (root->right==NULL)?0:root->right->val;
    int sum =l+r;

    if(sum>=root->val){
        root->val = l+r;
    }
    else{
        if(root->left){
            root->left->val+= (root->val)-sum;
        }
        else{
            root->right->val+= (root->val)-sum;
        }
    }

    solve(root->left);
    solve(root->right);

    sum = 0;
    if(root->left)sum+=root->left->val;
    if(root->right)sum+=root->right->val;

    if(root->left || root->right){
        root->val = sum;
    }
}

TreeNode* ChildrenSumProp(TreeNode* root){
    if(root==NULL)return root;
    solve(root);
    return root;
}
