#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


double Fknap(vector<int>&wt,vector<int>&val,int n,int capacity){
    vector<pair<int,int>>arr(n);

    for(int i=0;i<n;i++){
        arr[i]={wt[i],val[i]};
    }

    sort(arr.begin(),arr.end(),[](pair<int,int> &a,pair<int,int> &b){
        double op1 = (double)a.second/a.first ;
        double op2 = (double)b.second/b.first;

        if(op1==op2){
            return a.second>b.second;
        }
        return op1>op2;
    });

    double ans =0;
    for(int i=0;i<n;i++){
        if(capacity>=arr[i].first){
            ans+= (double)(arr[i].second);
            capacity-=arr[i].first;
        }
        else{
            double part = (double)arr[i].second/arr[i].first;
            ans+=(double)(part*capacity);
            break;
        }
    }
    return ans;
}

int main(){

}
