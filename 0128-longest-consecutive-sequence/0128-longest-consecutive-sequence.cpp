class Solution {
public:
    vector<int>parent;
    vector<int>size;

    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int dx = find(x);
        int dy = find(y);
        if(dx==dy)return;

        if(size[dx]>size[dy]){
            parent[dy]=dx;
            size[dx]+=size[dy];
        }
        else{
            parent[dx]=dy;
            size[dy]+=size[dx];
        }
    }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        unordered_map<int,int>idx;

        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i<nums.size();i++){
            if(idx.find(nums[i])==idx.end()){
                idx[nums[i]]=i;
            }
        }

        for(auto &i:idx){
            int ind = i.second;
            int n = i.first;

            if(idx.find(n+1)!=idx.end()){
                Union(ind,idx[n+1]);
            }
        }

        int maxi = INT_MIN;

        for(int i=0;i<n;i++){
            if(parent[i]==i){
                maxi = max(maxi,size[i]);
            }
        }

        return maxi;
    }
};