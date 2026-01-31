#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int i= arr.size()-1;
    int j= arr.size()-1;

    cout<<arr[arr.size()-1]<<" ";
    while(i>=0){
        if(arr[i]>arr[j]){
            cout<<arr[i]<<" ";
            j=i;
        }
        i--;
    }
}