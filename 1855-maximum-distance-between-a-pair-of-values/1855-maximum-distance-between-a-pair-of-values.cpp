class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i =0;
        int j =0;
        int len = 0;

        while(i<nums1.size() && j<nums2.size()){
            while(i<nums1.size() && j<nums2.size() && nums1[i]<=nums2[j]){
                if(i<=j)len = max(len,j-i);
                j++;
            }
            i++;
        }

        return len;
    }
};