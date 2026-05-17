class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr.size()==1)return true;
        vector<bool>vis(arr.size(),false);
        queue<int>q;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(arr[node]==0)return true;

            if(node+arr[node]<arr.size() && !vis[node+arr[node]]){
                vis[node+arr[node]]=true;
                q.push(node+arr[node]);
            }
            if(node-arr[node]>=0 && !vis[node-arr[node]]){
                vis[node-arr[node]]=true;
                q.push(node-arr[node]);
            }
        }

        return false;
    }
};