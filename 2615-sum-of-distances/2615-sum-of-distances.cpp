class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long>ans(nums.size(),0);
        unordered_map<int,vector<long long>>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]].push_back(i);
            }
            else{
                long long back = mp[nums[i]].back();
                mp[nums[i]].push_back(back+i);
            }
        }

        for(auto &temp:mp){
            for(int i=0;i<temp.second.size();i++){
                long long back = 0;
                if(i>0)back = temp.second[i-1];
                long long idx = temp.second[i]-back;
                long long left = (long long)i*idx -back;
                long long right = temp.second[temp.second.size()-1]-temp.second[i]-(long long)(temp.second.size()-i-1)*idx;
                ans[idx]=left+right;
            }
        }
        return ans;
    }
};