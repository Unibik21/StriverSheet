class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int size) {
        if(hand.size()%size!=0)return false;

        map<int,int>freq;
        for(int i=0;i<hand.size();i++){
            freq[hand[i]]++;
            
        }

        for(auto &i:freq){
            int pt = i.first;
            int f = i.second;

            while(f>0){
                for(int j=pt;j<pt+size;j++){
                    if(freq.find(j)==freq.end() || freq[j]==0)return false;
                    freq[j]--;
                }
                f--;
            }
        }

        return true;


    }
};