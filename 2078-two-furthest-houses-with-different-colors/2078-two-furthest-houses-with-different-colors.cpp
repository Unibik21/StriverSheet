class Solution {
public:
    int maxDistance(vector<int>& colors) {
       int lh = colors[0];
       int rh = colors[colors.size()-1];
        int n = colors.size();
        int left =-1;
        int rig = -1;
        bool a = false;
       for(int i=0;i<colors.size();i++){
            if(lh!=colors[i]){
                left = i;
            }
            if(!a && rh!=colors[i]){
                rig = abs(n-1-i);
                a= true;
            }

       } 

       return max(left,rig);
    }
};