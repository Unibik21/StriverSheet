class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mat;
        for(char ch:word){
            mat[ch]++;
        }
        int cnt=0;
        for(auto &it:mat){
            char ch = it.first;
            if(mat.find(ch-32)!=mat.end()){
                cnt++;
                mat.erase(ch-32);
            }
        }
        return cnt;
    }
};