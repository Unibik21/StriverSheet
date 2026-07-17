class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int>freq;
        unordered_map<char,int>fidx;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                freq[s[i]]++;
                if(fidx.find(s[i])==fidx.end()){
                    fidx[s[i]]=i;
                }
            }
        }

        string ans;
        int cnt= 0;
        char ch='\0';
        for(auto &i:s){
            if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u'){
                if(cnt==0){
                    freq.erase(ch);
                    auto it = max_element(freq.begin(),freq.end(),[&](auto &a,auto &b){
                        if(a.second==b.second) return fidx[a.first] > fidx[b.first];
                        return a.second<b.second;
                    });

                    ch = it->first;
                    cnt = it->second;
                    ans+=ch;
                    cnt--;
                }
                else{
                    ans+=ch;
                    cnt--;
                }
            }
            else{
                ans+=i;
            }
        }

        return ans;
    }
};