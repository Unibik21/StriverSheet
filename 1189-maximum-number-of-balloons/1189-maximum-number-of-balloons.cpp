class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>freq;
        for(char ch: text){
            freq[ch]++;
        }
        int maxi = INT_MAX;
        maxi = min(maxi,freq['b']);
        maxi = min(maxi,freq['a']);
        maxi = min(maxi,freq['n']);
        while(maxi>0){
            if(2*maxi<=freq['l'] && 2*maxi<=freq['o'])return maxi;
            maxi--;
        }

        return maxi;
    }
};