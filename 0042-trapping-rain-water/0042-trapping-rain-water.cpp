class Solution {
public:
    int trap(vector<int>& h) {
        vector<int>gl(h.size());
        vector<int>gr(h.size());

        gl[0]=h[0];
        gr[h.size()-1]=h[h.size()-1];
        int maxi = gl[0];
        for(int i=1;i<h.size();i++){
            maxi = max(maxi,h[i]);
            gl[i]=maxi;
        }
        maxi = gr[h.size()-1];
        for(int i=h.size()-1;i>=0;i--){
            maxi=max(maxi,h[i]);
            gr[i]=maxi;
        }

        int ans =0;
        for(int i=1;i<h.size()-1;i++){
            int minh = min(gl[i],gr[i]);
            ans+=minh-h[i];
        }

        return ans;
    }
};