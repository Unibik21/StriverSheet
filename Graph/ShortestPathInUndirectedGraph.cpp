#include<vector>
#include<iostream>
#include<queue>
using namespace std;

vector<int> ShortestPath(vector<vector<int>>&edges,int n,int m,int src){
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>dist(n,INT_MAX);
    queue<pair<int,int>>q;
    q.push({src,0});
    dist[src]=0;

    while(!q.empty()){
        int node = q.front().first;
        int d = q.front().second;
        q.pop();

        for(auto &it:adj[node]){
            if(dist[it]>d+1){
                dist[it]=d+1;
                q.push({it,d+1});
            }
        }
    }
    return dist;
}



int main(){

}