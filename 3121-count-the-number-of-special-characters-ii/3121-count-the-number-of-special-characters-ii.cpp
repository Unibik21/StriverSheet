class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>last;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(islower(ch)){
                last[ch]=i;
            }
        }

        int cnt =0;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(isupper(ch) && last.count(tolower(ch)) && last[tolower(ch)]<i){
                cnt++;
                last.erase(tolower(ch));
            }
            else if(isupper(ch) && last.count(tolower(ch))){
                last.erase(tolower(ch));
            }
        }
        return cnt;
    }
};