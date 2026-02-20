#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int>rank,parent,size;

public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=i;
        }
    }

    int findUpar(int node){
        if(node==parent[node])return node;
        return parent[node]=findUpar(parent[node]);
        
    }

    void unionByRank(int u,int v){
        int upu = findUpar(u);
        int upv = findUpar(v);

        if(upu==upv) return;

        if(rank[upu]>rank[upv]){
            parent[upv]=upu;
        }
        else if(rank[upu]<rank[upv]){
            parent[upu]=upv;
        }
        else{
            parent[upu]=upv;
            rank[upv]++;
        }
    }
    
    void unionBySize(int u,int v){
        int upu = findUpar(u);
        int upv = findUpar(v);

        if(upu==upv) return;
        if(size[upu]>size[upv]){
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
        else{
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
    }

};

int main(){

}