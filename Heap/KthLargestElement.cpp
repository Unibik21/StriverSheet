#include<iostream>
#include<queue>
using namespace std;

int solve(vector<int>&arr,int k){
    priority_queue<int>pq;

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
    
}