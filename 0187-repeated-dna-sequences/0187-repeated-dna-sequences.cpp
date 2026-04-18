class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int l =0;
        int r = 9;
        vector<string>ans;
        if(s.size()<10)return ans;
        unordered_map<string,int>freq;
        while(r<s.size()){
            string st = s.substr(l,10);
            freq[st]++;
            if(freq[st]==2)ans.push_back(st);
            l++;
            r++;
        }

        return ans;
    }
};