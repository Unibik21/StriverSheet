class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        unordered_map<string,string>mp;
        for(auto &i:knowledge){
            string key = i[0];
            string val = i[1];

            mp[key]=val;
        }
        int i =0;
        while(i<s.size()){
            if(s[i]=='('){
                string temp = "";
                i++;
                while(i<s.size() && s[i]!=')'){
                    temp+=s[i];
                    i++;
                }
                if(mp.find(temp)==mp.end())ans+='?';
                else ans+=mp[temp];
            }
            else{
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};