class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>cnt(26,0);

        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;
        }
        string ans = "";
        char mid = 0;
        for(int i=0;i<cnt.size();i++){
            ans.append(cnt[i]/2,char(i+'a'));

            if(cnt[i]%2==1){
                mid = char(i+'a');
            }
        }

        string temp = ans;
        reverse(temp.begin(),temp.end());
        
        if(mid){
            return ans+mid+temp;
        }

        return ans+temp;

    }
};