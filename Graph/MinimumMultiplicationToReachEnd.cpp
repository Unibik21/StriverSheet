#include<vector>
#include<iostream>
#include<queue>
using namespace std;


int miniMultiplication(vector<int>&arr,int start,int end){
    int MOD = 1e5;
    vector<int>dist(MOD,INT_MAX);
    queue<pair<int,int>>q;
    q.push({0,start});
    dist[start]=0;

    while(!q.empty()){
        int node = q.front().second;
        int d = q.front().first;
        q.pop();

        for(int i=0;i<arr.size();i++){
            int adjNode = (1LL*node*arr[i])%MOD;
            if(adjNode==end)return d+1;
            else if(dist[adjNode]>d+1){
                dist[adjNode]=d+1;
                q.push({d+1,adjNode});
            }
        }
    }
    return -1;
}