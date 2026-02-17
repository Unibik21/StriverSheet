#include<vector>
#include<iostream>
#include<queue>
using namespace std;

void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans){
    vis[node]=1;
    ans.push_back(node);
    for(auto &it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ans);
        }
    }
}