class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        for(int i=0;i<m;i++){
            string temp = "";
            if(i==m-1){
                for(int j=0;j<n;j++)temp+=".";
            }
            else{
                temp+='.';
                for(int j=1;j<n;j++)temp+='#';
            }
            ans.push_back(temp);
        }
        return ans;
    }
};