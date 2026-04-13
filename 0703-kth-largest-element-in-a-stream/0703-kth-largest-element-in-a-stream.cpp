class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int size=0;
    int req;
    KthLargest(int k, vector<int>& nums) {
        req=k;
        if(nums.size()==0)return;
        if(k>nums.size()){
            for(int i=0;i<nums.size();i++){
                pq.push(nums[i]);
            }
            size = nums.size();
            return;
        }
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        size = pq.size();
    }
    
    int add(int val) {
        if(pq.empty() || size<req){
            pq.push(val);
            size++;
            return pq.top();
        }
        if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */