class Solution {
public:
    int minimumPushes(string word) {
        int cnt = 0;
        int size = word.size();
        int add = 1;
        int ans =0;
        while(size){
            if(cnt==8){
                cnt=0;
                add++;
            }
            ans+=add;
            cnt++;
            size--;
        }
        return ans;
    }
};