class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>val;
        for(int i=0;i<arr.size();i++){
            val[arr[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>vis(arr.size(),-1);
        vis[0]=0;
        while(!q.empty()){
            auto [i,cnt] = q.front();
            q.pop();
            if(i==arr.size()-1){
                return cnt;
            }

            if(i+1<arr.size() && (vis[i+1]==-1 || vis[i+1]>cnt+1)){
                vis[i+1]=cnt+1;
                q.push({i+1,cnt+1});
            }
            if(i-1>=0 && (vis[i-1]==-1 || vis[i-1]>cnt+1)){
                vis[i-1]=cnt+1;
                q.push({i-1,cnt+1});
            }
            for(auto &j:val[arr[i]]){
                if(j!=i && (vis[j]==-1 || vis[j]>cnt+1)){
                    vis[j]=cnt+1;
                    q.push({j,cnt+1});
                }
            }

            val[arr[i]].clear();
        }
        return -1;
    }
};