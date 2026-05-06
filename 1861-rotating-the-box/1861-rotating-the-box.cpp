class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        for(int i=0;i<boxGrid.size();i++){
            int l = boxGrid[0].size()-1;
            for(int j=boxGrid[0].size()-1;j>=0;j--){
                if(boxGrid[i][j]=='#'){
                    boxGrid[i][j]='.';
                    boxGrid[i][l]='#';
                    l--;
                }
                else if(boxGrid[i][j]=='*'){
                    l=j-1;
                }
            }
        }

        vector<vector<char>>ans(boxGrid[0].size(),vector<char>(boxGrid.size()));
        for(int i=0;i<boxGrid.size();i++){
            for(int j=0;j<boxGrid[0].size();j++){
                ans[j][i]=boxGrid[i][j];
            }
        }

        for(int i=0;i<ans.size();i++){
            reverse(ans[i].begin(),ans[i].end());
        }

        return ans;
    }
};