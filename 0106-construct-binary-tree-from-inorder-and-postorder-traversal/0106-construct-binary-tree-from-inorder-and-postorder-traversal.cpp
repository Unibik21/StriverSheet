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
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        if(post.size()==0)return NULL;
        TreeNode* root = new TreeNode(post[post.size()-1]);

        int le = -1;
        int rs = in.size();

        for(int i=0;i<in.size();i++){
            if(in[i]==root->val){
                le = i;
                rs = i+1;
                break;
            }
        }

        if(le!=-1){
            vector<int>in1(in.begin(),in.begin()+le);
            vector<int>post1(post.begin(),post.begin()+le);

            root->left = buildTree(in1,post1);
        }

        if(rs!=in.size()){
            vector<int>in1(in.begin()+rs,in.end());
            vector<int>post1(post.begin()+le,post.end()-1);

            root->right = buildTree(in1,post1);
        }

        return root;
    }
};