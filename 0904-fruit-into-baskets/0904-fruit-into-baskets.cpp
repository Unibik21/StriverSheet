class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>cnt;
        int maxi = 0;

        int l =0;
        int r=0;

        while(r<fruits.size()){
            cnt[fruits[r]]++;
            while(cnt.size()>2){
                cnt[fruits[l]]--;
                if(cnt[fruits[l]]==0)cnt.erase(fruits[l]);
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};