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

bool dfs(TreeNode* root,vector<int>&ans, int k){
    if(root==NULL)return false;

    ans.push_back(root->val);
    if(root->val==k)return true;
    if(dfs(root->left,ans,k) || dfs(root->right,ans,k)){
        return true;
    }
    ans.pop_back();
    return false;
}

vector<int>Print(TreeNode *root,int target){
    vector<int>ans;
    if(root==NULL)return ans;
    
    dfs(root,ans,target);

    return ans;
}

int main(){

}