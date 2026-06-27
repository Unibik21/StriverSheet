class Solution {
public:
    int trap(vector<int>& h) {
        int l=0;
        int r = h.size()-1;
        int lmax =0;
        int rmax =0;
        int total =0;

        while(l<r){
            if(h[l]<=h[r]){
                if(h[l]<lmax){
                    total+=lmax-h[l];
                }
                else{
                    lmax=h[l];
                }
                l++;
            }
            else{
                if(h[r]<rmax){
                    total += rmax-h[r];
                }
                else{
                    rmax=h[r];
                }
                r--;
            }
        }

        return total;
    }
};