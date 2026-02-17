#include<vector>
#include<iostream>
#include<queue>
using namespace std;

bool detect(int src,vector<int>&vis,vector<int>adj[]){
    queue<pair<int,int>>q;
    q.push({src,-1});
    vis[src]=1;
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto &it: adj[node]){
            if(vis[it]==0){
                vis[it]=1;
                q.push({it,node});
            }
            else if(parent!=it){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int v, vector<int>adj[]){
    vector<int>vis(v,0);
    bool ans = false;
    for(int i=0;i<v;i++){
        if(vis[i]==0){
            ans = detect(i,vis,adj);
        }
    }
    return ans;
}