class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        queue<int>q;
        for(int i=1;i<=8;i++)q.push(i);

        while(!q.empty()){
            int num = q.front();
            q.pop();
            if(num>=low && num<=high)ans.push_back(num);
            int d = num%10;
            if(d!=9){
                num = num*10+(d+1);
                if(num<=high)q.push(num);
            }
        }

        return ans;

    }
};