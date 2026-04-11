class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        vector<vector<int>>bucket(n+1);

        for(auto &i:freq){
            bucket[i.second].push_back(i.first);
        }
        vector<int>ans;

        for(int i=n;i>=0;i--){
            for(auto &j:bucket[i]){
                ans.push_back(j);
                if(ans.size()==k)return ans;
            }
        }

        return ans;
    }
};