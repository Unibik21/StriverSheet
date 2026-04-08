#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int kthLargest(vector<int>arr,int k){
    priority_queue<int,vector<int>>pq;
    for(int i=0;i<arr.size();i++){
        pq.push(arr[i]);
    }
    while(k-1>0){
        pq.pop();
        k--;
    }
    return pq.top();
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<< kthLargest(arr,k);
}