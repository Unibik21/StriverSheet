#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;

int solve(string s,int k){
    unordered_map<char,int>cnt;
    int ans = 0;
    int l =0;
    for(int r = 0;r<s.size();r++){
        cnt[s[r]]++;
        
        while(k<cnt.size()){
            cnt[s[l]]--;
            if(cnt[s[l]]==0) cnt.erase(s[l]);
            l++;
        }

        ans+=(r-l+1);
    }
    return ans;
}


int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;

    int ans = solve(s,k)-solve(s,k-1);

    cout<<ans<<endl;

    

}