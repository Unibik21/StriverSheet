#include<vector>
#include<iostream>
#include<queue>
using namespace std;


vector<int>topoSort(int v,vector<int>adj[]){
    vector<int>ind(v,0);

    for(int i=0;i<v;i++){
        for(auto &it:adj[i]){
            ind[it]++;
        }
    }

    queue<int>q;
    for(int i=0;i<v;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }

    vector<int>ans;
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto &it:adj[node]){
            ind[it]--;
            if(ind[it]==0){
                q.push(it);
            }
        }
    }
    return ans;
}

int main(){

}