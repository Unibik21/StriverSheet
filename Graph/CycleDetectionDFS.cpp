#include<vector>
#include<iostream>
#include<queue>
using namespace std;

bool dfs(int src,int parent,vector<int>adj[],vector<int>&vis){
    vis[src]=1;

    for(auto &it:adj[src]){
        if(!vis[it]){
            if(dfs(it,src,adj,vis))return true;
        }
        else if(parent!=it){
            return true;
        }
    }
    return false;
}

bool isCycle(int v,vector<int>adj[]){
    vector<int>vis(v,0);
    for(int i=0;i<v;i++){
        if(vis[i]==0){
            if(dfs(i,-1,adj,vis))return true;
        }
    }
    return false;
}