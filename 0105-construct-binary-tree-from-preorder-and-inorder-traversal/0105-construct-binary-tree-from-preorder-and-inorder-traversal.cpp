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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {

        if(pre.empty())return NULL;

        TreeNode* root= new TreeNode(pre[0]);
        int le = -1;
        int rs =in.size();

        for(int i=0;i<in.size();i++){
            if(pre[0]==in[i]){
                le = i;
                rs = i+1;
                break;
            }
        }

        if(le==-1){
            root->left=NULL;
        }
        else{
            vector<int>in1(in.begin(),in.begin()+le);
            vector<int>pre1(pre.begin()+1,pre.begin()+le+1);
            root->left = buildTree(pre1,in1);
        }

        if(rs==in.size()){
            root->right=NULL;
        }
        else{
            vector<int>in1(in.begin()+rs,in.end());
            vector<int>pre1(pre.begin()+le+1,pre.end());
            root->right = buildTree(pre1,in1);
        }

        return root;
    }
};