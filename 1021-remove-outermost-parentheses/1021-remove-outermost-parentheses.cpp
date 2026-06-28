class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt =0;
        string str="";
        for(auto &i:s){
          if(i=='('){
            if(cnt!=0)str+=i;
            cnt++;
          }
          else{
            if(cnt!=1)str+=i;
            cnt--;
          }      
        } 

        return str;
    }
};