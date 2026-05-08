class Solution {
public:
    vector<bool>isPrime;
    void Sieve(int maxi){
       isPrime.resize(maxi+1,true);
       isPrime[0]=false;
       isPrime[1]=false;

        for(int i=2;i*i<=maxi;i++){
            if(isPrime[i]){
               for(int m = i*i;m<=maxi;m+=i) isPrime[m]=false;
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        unordered_map<int,vector<int>>cnt;
        for(int i=0;i<nums.size();i++){
            maxi=max(nums[i],maxi);
            cnt[nums[i]].push_back(i);
        }

        Sieve(maxi);
        queue<int>q;
        q.push(0);
        vector<bool>visited(n,false);
        unordered_set<int>seen;
        visited[0]=true;
        int steps =0;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int idx = q.front();
                q.pop();
                if(idx==n-1)return steps;
                if(idx-1>=0 && !visited[idx-1]){q.push(idx-1);visited[idx-1]=true;}
                if(idx+1<n && !visited[idx+1]){q.push(idx+1);visited[idx+1]=true;}
                if(isPrime[nums[idx]] && seen.find(nums[idx])==seen.end()){
                    for(int m =nums[idx];m<=maxi;m+=nums[idx]){
                        if(cnt.find(m)!=cnt.end()){
                            for(auto &j: cnt[m]){
                                if(!visited[j]){
                                    q.push(j);
                                    visited[j]=true;
                                }
                            }
                        }
                    }
                }
                seen.insert(nums[idx]);
            }
            steps++;
        }
        return steps;
    }
};