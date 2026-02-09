#include<iostream>
#include<vector>
using namespace std;

bool isThere(int i,string s1,string s2){
    if(i+s2.size()>s1.size()) return false;
    int j=0;
    while(j<s2.size()){
        if(s1[i++]!=s2[j++]){
            return false;
        }
    }
    return true;

}

bool solve(int i,string s,vector<string>words){
    if(i==s.size()){
        return true;
    }

    for(int j=0;j<words.size();j++){
        if(isThere(i,s,words[j])){
            if(solve(i+words[j].size(),s,words)){
                return true;
            }
        }
    }
    return false;
}

int main(){

}