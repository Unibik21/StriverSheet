#include<vector>
#include<iostream>
#include<queue>
using namespace std;

vector<int>dijkstra(int v,vector<vector<int>>adj[],int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(v,1e9);
    dist[s]=0;
    pq.push({0,s});

    while(!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for(auto &it:adj[node]){
            int adjNode = it[0];
            int wt = it[1];
            
            if(dist[adjNode]> wt+d){
                dist[adjNode]= wt+d;
                pq.push({wt+d,adjNode});
            }
        }
    }
    return dist;
}