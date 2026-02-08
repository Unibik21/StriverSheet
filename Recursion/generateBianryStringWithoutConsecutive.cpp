#include<iostream>
#include<vector>

using namespace std;

void StringsWithoutConsecutive1s(int i,int n,vector<int>&arr){
    if(i>=n){
        for(int j=0;j<n;j++){
            cout<<arr[j]<<" ";
        }
        return;
    }

    arr.push_back(0);
    StringsWithoutConsecutive1s(i+1,n,arr);
    arr.pop_back();
    if(arr.empty() ||  arr.back()==0){
        arr.push_back(1);
        StringsWithoutConsecutive1s(i+1,n,arr);
        arr.pop_back();
    }
    return;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr;
    StringsWithoutConsecutive1s(0,n,arr);
}