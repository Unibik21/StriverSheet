class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        unordered_map<int,int>a;
        unordered_map<int,int>b;
        int cnt =0;
        for(int i=0;i<A.size();i++){
            a[A[i]]=0;
            b[A[i]]=0;
        }
        for(int i=0;i<A.size();i++){
            a[A[i]]++;
            b[B[i]]++;
            if(a[A[i]]==b[A[i]]){
                cnt++;
            }
            if(A[i]!=B[i] && b[B[i]]==a[B[i]]){
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};