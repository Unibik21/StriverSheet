class Solution {
public:
    void solve(int i,int n,int x,string s,vector<string>&ans){
        if(i==n){
            if(x==0)ans.push_back(s);
            return;
        }
        if(x<0)return;
        s+='(';
        solve(i+1,n,x+1,s,ans);
        s.pop_back();
        s+=')';
        solve(i+1,n,x-1,s,ans);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string>ans;
        solve(0,2*n,0,s,ans);
        return ans;
    }
};