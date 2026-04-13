class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>cnt;
        for(int i=0;i<tasks.size();i++){
            cnt[tasks[i]]++;
        }

        priority_queue<int>pq;
        for(auto &i:cnt){
            pq.push(i.second);
        }
        int intv = 0;
        while(!pq.empty()){
            vector<int>temp;
            int j =0;
            while(!pq.empty() && j<n+1){
                int m = pq.top()-1;
                if(m!=0)temp.push_back(m);
                pq.pop();
                j++;
            }
            for(int i=0;i<temp.size();i++){
                pq.push(temp[i]);
            }
            intv+= pq.empty()?j:n+1;
        }

        return intv;
    }
};