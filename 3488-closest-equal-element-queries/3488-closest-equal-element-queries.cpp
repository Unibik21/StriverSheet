class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>out;

        unordered_map<int,vector<int>>ind;
        for(int i=0;i<nums.size();i++){
            ind[nums[i]].push_back(i);
        }

        int n = nums.size();
        for(auto &i:queries){
            vector<int>&temp = ind[nums[i]];
            if(temp.size()==1){out.push_back(-1); continue;}
            int l=0;
            int h=temp.size()-1;
            int idx = -1;
            int dist = INT_MAX;
            while(l<=h){
                int m = l+(h-l)/2;
                if(temp[m]==i){
                    idx= m;
                    break;
                }
                else if(temp[m]>i){
                    h=m-1;
                }
                else{
                    l=m+1;
                }
            }

            if (idx > 0) {
                int j = temp[idx - 1];
                dist = min(dist, min(abs(j - i), n - abs(j - i)));
            }

            if (idx < temp.size() - 1) {
                int j = temp[idx + 1];
                dist = min(dist, min(abs(j - i), n - abs(j - i)));
            }

            int first = temp[0];
            int last = temp.back();

            if (first != i)
                dist = min(dist, min(abs(first - i), n - abs(first - i)));

            if (last != i)
                dist = min(dist, min(abs(last - i), n - abs(last - i)));

            out.push_back(dist);

        }

        return out;
    }
};