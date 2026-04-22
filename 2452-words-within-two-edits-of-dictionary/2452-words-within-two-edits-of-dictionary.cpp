class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(int i=0;i<queries.size();i++){
            string s = queries[i];
            for(int j=0;j<dictionary.size();j++){
                string t = dictionary[j];
                int cnt =0;
                for(int k=0;k<s.size();k++){
                    if(s[k]!=t[k])cnt++;
                }
                if(cnt<=2){ans.push_back(s); break;}
            }
        }
        return ans;
    }
};