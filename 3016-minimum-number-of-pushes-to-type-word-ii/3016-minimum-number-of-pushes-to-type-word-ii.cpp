class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>freq;
        for(auto &i:word)freq[i]++;
        set<pair<int,char>,greater<pair<int,char>>>desc;

        for(auto &i:freq){
            desc.insert({i.second,i.first});
        }

        int ans =0;
        int add=1;
        int cnt =0;

        for(auto &i:desc){
            int num = i.first;
            if(cnt==8){
                cnt=0;
                add++;
            }
            cnt++;
            ans+= num*add;
        }
        return ans;
    }
};