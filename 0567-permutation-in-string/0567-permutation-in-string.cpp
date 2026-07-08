class Solution {
public:
    bool check(int l,int r,string s, unordered_map<char,int>freq){
        for(int i=l;i<=r;i++){
            freq[s[i]]--;
            if(freq[s[i]]==0)freq.erase(s[i]);
        }
        return freq.size()==0;
    }
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>freq1;

        for(auto &i:s1)freq1[i]++;

        int l=0;
        int r=s1.size()-1;

        while(r<s2.size()){
            unordered_map<char,int>freq2=freq1;
            if(check(l,r,s2,freq2))return true;
            l++;
            r++;
        }

        return false;
    }
};