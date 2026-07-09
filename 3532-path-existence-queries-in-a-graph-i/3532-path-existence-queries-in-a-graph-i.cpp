class Solution {
public:
    class DSU{
        public:
            vector<int>parent,size;

            DSU(int n){
                parent.resize(n);
                size.resize(n,1);
                for(int i=0;i<n;i++)parent[i]=i;
            }

            int findPar(int node){
                if(node==parent[node])return node;
                return parent[node]=findPar(parent[node]);
            }

            void unionBySize(int u,int v){
                int pu = findPar(u);
                int pv = findPar(v);

                if(pu==pv)return;

                if(size[pu]>size[pv]){
                    parent[pv]=pu;
                    size[pu]+=size[pv];
                }
                else{
                    parent[pu]=pv;
                    size[pv]+=size[pu];
                }
            }
    };
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>adj[n];

        DSU ds(n);

        vector<pair<int,int>>arr;

        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }

        sort(arr.begin(),arr.end());

        for(int i=1;i<n;i++){
            if(arr[i].first-arr[i-1].first<=maxDiff)ds.unionBySize(arr[i].second,arr[i-1].second);
        }
       
        vector<bool>ans;
        for(auto &i:queries){
            int u = i[0];
            int v = i[1];

            if(ds.findPar(u)==ds.findPar(v))ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;


    }
};