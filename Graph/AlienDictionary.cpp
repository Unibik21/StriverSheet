#include<vector>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

string findOrder(string dict[],int n,int k){
    vector<vector<int>>adj(k);

    for(int i=0;i<n-1;i++){
        string one = dict[i];
        string two = dict[i+1];

        for(int j=0;j<min(one.size(), two.size());j++){
            if(one[j]!=two[j]){
                adj[one[j]-'a'].push_back(two[j]-'a');
                break;
            }
        }
    }

    vector<int>ind(k,0);

    for(int i=0;i<k;i++){
        for(auto &it:adj[i]){
            ind[it]++;
        }
    }

    queue<int>q;
    for(int i=0;i<k;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto &it:adj[node]){
            ind[it]--;
            if(ind[it]==0){
                q.push(it);
            }
        }
    }

    string res = "";
    for(auto &it : ans){
        res += char(it + 'a');
    }

    return res;

}