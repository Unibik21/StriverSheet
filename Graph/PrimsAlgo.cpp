#include<vector>
#include<iostream>
#include<queue>
using namespace std;


int spanningTree(int v,vector<vector<int>>adj[]){
    vector<int>vis(v,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    int sum =0;

    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(vis[node]==1)continue;

        vis[node]=1;
        sum+=wt;
        for(auto &it:adj[node]){
            int adjNode = it[0];
            int edgeWt = it[1];
            pq.push({edgeWt,adjNode});
            
        }
    }
    return sum;
}

int main(){

}