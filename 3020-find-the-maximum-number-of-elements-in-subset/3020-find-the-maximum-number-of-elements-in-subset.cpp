class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto &i:nums)freq[i]++;
        int maxi = 1;
        if(freq.count(1)){
            int ps = (freq[1]%2==0)?freq[1]-1:freq[1];
            maxi = max(maxi,ps);
        }

        for(auto &j:freq){
            long long num = j.first;
            int total = 0;
            if(num==1)continue;
            while(freq.count(num*num) && freq[num]>=2){
                if(num*num>1e9)break;
               total +=2;
               num=num*num;
            }
            total+=1;
            maxi=max(maxi,total);
        }

        return maxi;

    }
};