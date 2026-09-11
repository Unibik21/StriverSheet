class Solution {
public:
    int totalNumbers(vector<int>& d) {
        unordered_set<int>cnt;
       for(int i=0;i<d.size();i++){
        for(int j=0;j<d.size();j++){
            for(int k=0;k<d.size();k++){
                if(i!=j && j!=k && k!=i){
                    int num = d[i]*100+d[j]*10+d[k];
                    if(num%2==0 && num>=100 && num<=999)cnt.insert(num);
                }
            }
        }
       }
       return cnt.size();
    }
};