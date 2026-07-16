class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi =-1;
        vector<int>pref;
        for(auto &i:nums){
            maxi = max(maxi,i);
            pref.push_back(gcd(maxi,i));
        }

        sort(pref.begin(),pref.end());

        long long sum =0;
        int i=0;
        int j=nums.size()-1;

        while(i<j){
            sum+=gcd(pref[i],pref[j]);
            i++;
            j--;
        }

        return sum;
    }
};