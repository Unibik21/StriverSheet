class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long>arr(nums.size());

        unordered_map<int,long long>indSum;
        unordered_map<int,long long>freq;

        for(int i=0;i<nums.size();i++){
            if(indSum.find(nums[i])==indSum.end()){
                freq[nums[i]]=1;
                indSum[nums[i]]=i;
            }
            else{
                long long f = freq[nums[i]];
                long long lsum = indSum[nums[i]];
                arr[i]= (long long)f*i -(long long)lsum;
                freq[nums[i]]++;
                indSum[nums[i]]+=(long long)i;
            }
        }
        freq.clear();
        indSum.clear();
        for(int i=nums.size()-1;i>=0;i--){
            if(indSum.find(nums[i])==indSum.end()){
                freq[nums[i]]=1;
                indSum[nums[i]]=i;
            }
            else{
                long long f = freq[nums[i]];
                long long rsum = indSum[nums[i]];
                arr[i]+= (long long)rsum - (long long)f*i;
                freq[nums[i]]++;
                indSum[nums[i]]+=(long long)i;
            }
        }

        return arr;
    }
};