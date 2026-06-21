class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = -1;
        for(int i=0;i<costs.size();i++){
            if(maxi<costs[i]){
                maxi = costs[i];
            }
        }

        vector<int>cnt(maxi+1,0);

        for(auto &x:costs){
            cnt[x]++;
        }

        vector<int>nums;
        for(int i=0;i<cnt.size();i++){
            while(cnt[i]!=0){
                nums.push_back(i);
                cnt[i]--;
            }
        }

        int c = 0;
        for(int i=0;i<nums.size();i++){
            if(coins-nums[i]>=0){
                c++;
                coins-=nums[i];
            }
            else{
                break;
            }
        }

        return c;

    }
};