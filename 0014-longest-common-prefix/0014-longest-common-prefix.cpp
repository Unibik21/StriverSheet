class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s1= strs[0];
        string s2 = strs[strs.size()-1];
        string ans = "";
        int i=0;
        while(i<s1.size() && s1[i]==s2[i]){
            ans+=s1[i];
            i++;
        }
        return ans;

    }
};