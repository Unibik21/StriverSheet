#include<vector>
#include<iostream>
#include<stack>
using namespace std;

void dfs(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
    vis[node]=1;
    for(auto &it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,st,adj);
        }
    }
    st.push(node);
}

vector<int>topoSort(int v,vector<int>adj[]){
    vector<int>vis(v,0);
    stack<int>st;
    vector<int>ans;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){

}