class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt =0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;

        while(j<g.size() && i<s.size()){
            if(s[i]>=g[j]){
                i++;
                j++;
                cnt++;
            }
            else{
                i++;
            }
        }

        return cnt;
    }
};