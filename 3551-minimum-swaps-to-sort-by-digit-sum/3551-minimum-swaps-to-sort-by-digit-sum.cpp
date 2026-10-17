class Solution {
public:
    int minSwaps(vector<int>& nums) {
        unordered_map<int,int>pos;
        vector<int>temp =nums;
        sort(temp.begin(),temp.end(),[](auto a,auto b){
            int d1=0,d2=0;
            int t1=a,t2=b;
            while(t1){
                d1+=t1%10;
                t1/=10;
            }
            while(t2){
                d2+=t2%10;
                t2/=10;
            }

            if(d1==d2){
                return a<b;
            }
            return d1<d2;
        });
        for(int i=0;i<nums.size();i++)pos[nums[i]]=i;
        int swap=0;
        for(int i=0;i<nums.size();i++){
            int expV = temp[i];
            int currV = nums[i];

            if(currV==expV)continue;

            int idx = pos[expV];
            nums[i]=expV;
            nums[idx]=currV;
            pos[currV]=idx;
            pos[expV]=i;
            swap++;
        }
        return swap;
        
    }
};