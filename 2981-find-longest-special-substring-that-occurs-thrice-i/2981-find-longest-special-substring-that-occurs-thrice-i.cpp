class Solution {
public:
    bool check(const string &sub){
        for(int i=0;i<sub.size()-1;i++){
            if(sub[i]!=sub[i+1])return false;
        }
        return true;
    }
    bool solve(string &s,int m){
        int l=0;
        int r=m-1;
        unordered_map<string,int>cnt;
        while(r<s.size()){
            cnt[s.substr(l,r-l+1)]++;
            l++;
            r++;
        }
        for(auto &i:cnt){
            if(!check(i.first))continue;
            if(i.second>=3)return true;
        }
        return false;;
    }
    int maximumLength(string s) {
        int l =1;
        int h = s.size()-1;
        int ans = 0;

        while(l<=h){
            int m = l+(h-l)/2;

            if(solve(s,m)){
                ans = m;
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return ans==0?-1:ans;
    }
};