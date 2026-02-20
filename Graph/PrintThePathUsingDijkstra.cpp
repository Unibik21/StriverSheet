#include<vector>
#include<iostream>
#include<queue>
using namespace std;


vector<int>shortestPath(int n,int m,vector<vector<int>>&edges){
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    vector<int>parent(n+1);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    vector<int>dist(n+1,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;

        for(auto &it:adj[node]){
            int adjNode = it.first;
            int edgeDist = it.second;

            if(d+edgeDist<dist[adjNode]){
                dist[adjNode]=d+edgeDist;
                pq.push({d+edgeDist,adjNode});
                parent[adjNode]=node;
            }
        }
    }
    vector<int>ans;
    int node = n;
    while(parent[node]!=node){
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());

    return ans;
    
}