class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>>ind;

        for(int i=0;i<arr.size();i++){
            ind[arr[i]].push_back(i);
        }

        int r =1;
        vector<int>ans(arr.size());

        for(auto &i:ind){
            for(auto &j:i.second){
                ans[j]=r;
            }
            r++;
        }

        return ans;

    }
};