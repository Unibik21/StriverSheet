#include<iostream>
#include<stack>
using namespace std;

int priority(char ch){
    if(ch=='^') return 3;
    else if (ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else return -1;
}

void solve(int i,string s,string &ans, stack<char>&st){
    while(i<s.size()){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty())st.pop();
        }
        else{
            while(!st.empty() && priority(s[i])<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
}

int main(){
    string s;
    cin>>s;
    string ans="";
    stack<char>st;
    solve(0,s,ans,st);
}