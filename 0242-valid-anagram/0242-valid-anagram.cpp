class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>freq;
        for(auto &i:s)freq[i]++;
        for(auto &j:t){
            if(freq.find(j)!=freq.end()){
                freq[j]--;
                if(freq[j]==0)freq.erase(j);
            }
            else{
                return false;
            }
        }
        return freq.size()==0;
    }
};