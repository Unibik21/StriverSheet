#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int solve(int k,string s){
    unordered_map<char,int>freq;
    int l=0;
    int r=0;
    int cnt =0;
    while(r<s.size()){
        freq[s[r]]++;
        while(freq.size()>k){
            freq[s[l]]--;
            if(freq[s[l]]==0){
                freq.erase(s[l]);
            }
            l++;
        }
        cnt = max(cnt,r-l+1);
        r++;
    }
    return cnt;
}