// TC - n+m
// SC - n+m

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr1(n);
    vector<int>arr2(m);

    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }

    int t =0;
    int b =0;
    
    queue<int>q;

    for(int i=0;i<min(m,n);i++){
        if(arr1[t]<arr2[b] && q.front()!=arr1[t]){
            q.push(arr1[t]);
            t++;
        }
        if(arr1[t]>arr2[b] && q.front()!=arr2[b]){
            q.push(arr2[b]);
            b++;
        }
        if(arr1[t]==arr2[b] && q.front()!=arr2[b]){
            q.push(arr2[b]);
            t++;
            b++;
        }
        if(arr1[t]==arr2[b] && q.front()==arr2[b]){
            t++;
            b++;
        }
    }

    while(t<n){
        if(q.front()!=arr1[t]) q.push(arr1[t]);
        t++;
    }
    while(b<m){
        if(q.front()!=arr2[b]) q.push(arr2[b]);
        b++;
    }

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}