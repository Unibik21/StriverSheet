class Solution {
public:
    string largestOddNumber(string num) {
        int j = num.size();
        while(j>=0){
            int n = num[j]-'0';
            if(n%2!=0)break;
            j--;
        }

        if(j<0)return "";
        return num.substr(0,j+1);
    }
};