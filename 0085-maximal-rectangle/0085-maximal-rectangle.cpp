class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        vector<int>pse(h.size());
        vector<int>nse(h.size());

        pse[0]=-1;
        stack<int>st;
        for(int i=0;i<h.size();i++){
            while(!st.empty() && h[st.top()]>h[i])st.pop();
            if(st.empty())pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        nse[h.size()-1]=h.size();
        while(!st.empty())st.pop();
        for(int i=h.size()-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>=h[i])st.pop();
            if(st.empty())nse[i]=h.size();
            else nse[i]=st.top();
            st.push(i);
        }

        int area=0;
        for(int i=0;i<h.size();i++){
            area = max(area,(nse[i]-pse[i]-1)*h[i]);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        vector<int>temp(mat[0].size());
        int maxi =0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]=='0')temp[j]=0;
                else temp[j]+=1;
            }
            maxi=max(maxi,largestRectangleArea(temp));
        }
        return maxi;
    }
};