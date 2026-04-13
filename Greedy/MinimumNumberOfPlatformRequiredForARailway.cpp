#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int solve(vector<int>arr,vector<int>dep,int n){
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());

    int i=0,j=0;
    int maxCnt = 0;
    int cnt =0;

    while(i<n){
        if(arr[i]<=dep[j]){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        maxCnt = max(maxCnt,cnt);
    }
    return maxCnt;
}
int main(){

}