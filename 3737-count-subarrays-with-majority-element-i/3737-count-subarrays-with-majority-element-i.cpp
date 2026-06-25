class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt =0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>freq;
            for(int j=i;j>=0;j--){
                freq[nums[j]]++;
                if(freq.find(target)!=freq.end() && freq[target]>((i-j+1)/2))cnt++;
            }
        }

        return cnt;
    }
};