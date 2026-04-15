class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int idx = INT_MAX;
        for(int i=startIndex;i<startIndex+n;i++){
                if(target==words[i%n]){
                    idx = min({idx,abs(i-startIndex),abs(n-i+startIndex)});
                }
        }
        return idx==INT_MAX?-1:idx;
    }
};