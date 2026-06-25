class Solution {
public:
    int numberOfSubstrings(string nums) {
        int ls[3];
        for(int i=0;i<3;i++)ls[i]=-1;

        int l=0;
        int r =0;
        int cnt =0;
        while(r<nums.size()){
            ls[nums[r]-'a']=r;
            if(ls[0]!=-1 && ls[1]!=-1 && ls[2]!=-1){
                cnt+=1+min({ls[0],ls[1],ls[2]});
            }
            r++;
        }

        return cnt;
    }
};