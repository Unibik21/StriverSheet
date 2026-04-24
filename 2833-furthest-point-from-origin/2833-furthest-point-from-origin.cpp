class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
       int r= 0;
       int l=0;
       for(int i=0;i<moves.size();i++){
        if(moves[i]=='L')l++;
        else if(moves[i]=='R')r++;
       } 
       int b = moves.size()-r-l;

       if(r>=l)return r+b-l;
       return l+b-r;
    }
};