#include<iostream>
#include<vector>
#include<algorithm>
#include <tuple>
using namespace std;


vector<int>solve(vector<int>&start,vector<int>&end,int n){
    vector<tuple<int,int,int>>arr;
    for(int i=0;i<n;i++){
        arr.push_back({end[i],start[i],i+1});
    }
    sort(arr.begin(),arr.end());
    
    vector<int>ans;
    int last =-1;

    for(auto &m:arr){
        int s = get<1>(m);
        int e = get<0>(m);
        int idx = get<2>(m);

        if(s>=last){
            ans.push_back(idx);
            last = e;
        }
    }

    return ans;
}

int main(){

}