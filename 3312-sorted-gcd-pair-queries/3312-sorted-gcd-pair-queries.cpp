class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxi =-1;
        for(auto &i:nums)maxi = max(maxi,i);

        vector<long long>cnt(maxi+1);

        for(int i=0;i<nums.size();i++)cnt[nums[i]]++;

        for(int i=1;i<=maxi;i++){
            for(int j=i*2;j<=maxi;j+=i) cnt[i]+=cnt[j];
        }

        for(int i=1;i<cnt.size();i++){
            cnt[i]= ((cnt[i])*(cnt[i]-1))/2;
        }

        for(int i=maxi;i>=1;i--){
            for(int j=i*2;j<=maxi;j+=i){
                cnt[i]-=cnt[j];
            }
        }

        for(int i=1;i<cnt.size();i++)cnt[i]+=cnt[i-1];
        vector<int>ans;
        for(auto idx:queries){
            idx++;
            int num = lower_bound(cnt.begin(),cnt.end(),idx)-cnt.begin();
            ans.push_back(num);
        }

        return ans;
    }
};