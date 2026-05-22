class Solution {
    class DSU{
        vector<int>parent,size;
        public:
            DSU(int n){
                parent.resize(n);
                size.resize(n,1);
                for(int i=0;i<n;i++) parent[i]=i;
            }
        
        int findParent(int u){
            if(parent[u]==u)return u;
            return parent[u]= findParent(parent[u]);
        }
        void unionBySize(int u,int v){
            int pu = findParent(u);
            int pv = findParent(v);

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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>par;
        DSU ds(accounts.size());
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(par.find(accounts[i][j])==par.end())par[accounts[i][j]]=i;
                else ds.unionBySize(par[accounts[i][j]],i);
            }
        }
        int n = accounts.size();
        vector<vector<string>>mails(n);
        for(auto &it:par){
            string mail = it.first;
            int node = ds.findParent(it.second);
            mails[node].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i=0;i<n;i++){
            if(mails[i].size()==0)continue;
            vector<string>temp;
            sort(mails[i].begin(),mails[i].end());
            temp.push_back(accounts[i][0]);
            for(auto &it:mails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};