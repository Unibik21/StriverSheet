class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>idx;

       for(int i=0;i<nums.size();i++){
        idx[nums[i]].push_back(i);
       } 
       int mini = INT_MAX;

       for(auto &i:idx){
            vector<int>ind = i.second;
            if(ind.size()>=3){
                for(int j=0;j<=ind.size()-3;j++){
                    int o =ind[j];
                    int t = ind[j+1];
                    int w = ind[j+2];

                    mini = min(mini,abs(o-t)+abs(t-w)+abs(w-o));
                }
            }
       }

       return mini==INT_MAX?-1:mini;
    }
};