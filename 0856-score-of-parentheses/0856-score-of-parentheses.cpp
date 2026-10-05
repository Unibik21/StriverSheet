class Solution {
public:
    int solve(int i,int j,string &s){
        int x =0;
        int ans =0;

        for(int k=i;k<=j;k++){
           x+=(s[k]==')' ? -1:1);

           if(x==0){
                if(k-i==1)ans++;
                else ans+= 2*solve(i+1,k-1,s);
                i=k+1;
           } 
        }
        return ans;
    }
    int scoreOfParentheses(string s) {
        return solve(0,s.size()-1,s);
    }
};