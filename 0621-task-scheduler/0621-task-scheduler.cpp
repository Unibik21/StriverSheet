class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]]++;
        }

        priority_queue<int>pq;

        for(auto &i:freq){
            pq.push(i.second);
        }
        int ans =0;
        while(!pq.empty()){
            int j =0;
            vector<int>temp;
            while(!pq.empty() && j<n+1){
                int f = pq.top();
                pq.pop();
                if(f-1!=0)temp.push_back(f-1);
                j++;
            } 

            for(int i=0;i<temp.size();i++){
                pq.push(temp[i]);
            }
            ans+= pq.empty()?j:n+1;
        }

        return ans;
    }
};