#include<iostream>
#include<vector>

using namespace std;

void powerSet(int i,string &s,string &s1){
    if(i==s.size()){
        cout<<s1<<endl;
        return;
    }

    s1+=s[i];
    powerSet(i+1,s,s1);
    s1.pop_back();
    powerSet(i+1,s,s1);
    return;
}


int main(){
    string s;
    cin>>s;
    string s1;
    powerSet(0,s,s1);
}