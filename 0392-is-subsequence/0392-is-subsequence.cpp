class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        while(j<t.size()){
            if(i==s.size())return true;
            if(s[i]==t[j]){j++;i++;}
            else j++;
        }

        return i==s.size();
    }
};