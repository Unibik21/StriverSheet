#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(int i,int j,string s){
    while(i<j){
        if(s[i++]!=s[j--]){
            return false;
        }
    }
    return true;
}

void PalindromicPartition(int i,string s,vector<string>&a1,vector<vector<string>>&ans){
    if(i==s.size()){
        ans.push_back(a1);
        return;
    }

    for(int j=i;j<s.size();j++){
        if(isPalindrome(i,j,s)){
            a1.push_back(s.substr(i,j-i+1));
            PalindromicPartition(j+1,s,a1,ans);
            a1.pop_back();
        }
    }
}

int main(){

}