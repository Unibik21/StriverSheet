#include<iostream>
#include<queue>
using namespace std;


vector<int> solve(vector<int>&nums,int k){
    vector<int>ans;

    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }
    for(int i=k;i<nums.size();i++){
        ans.push_back(pq.top());
        pq.pop();
        pq.push(nums[i]);
    }

    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}