#include<iostream>
#include<vector>
using namespace std;

vector<int>bellmanFord(int v,vector<vector<int>>&edges,int s){
    vector<int>dist(v,1e8);
    dist[s]=0;
    for(int i=0;i<v-1;i++){
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    vector<int>curr_dist=dist;
    for(auto &it:edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if(dist[u]+wt<dist[v]){
            dist[v]=dist[u]+wt;
        }
    }

    if(curr_dist==dist){
        return curr_dist;
    }
    else return {-1};
}

int main(){

}