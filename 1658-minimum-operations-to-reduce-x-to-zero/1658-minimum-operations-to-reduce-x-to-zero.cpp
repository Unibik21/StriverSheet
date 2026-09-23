class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        vector<int> pref(n, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0) pref[i] = nums[i];
            else pref[i] = pref[i - 1] + nums[i];
        }

        vector<int> suff(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) suff[i] = nums[i];
            else suff[i] = suff[i + 1] + nums[i];
        }

        int total = pref[n - 1];

        if (x > total) return -1;
        if (x == total) return n;

        int ans = n;

        for (int i = -1; i < n; i++) {
            int lsum = (i == -1 ? 0 : pref[i]);

            if(lsum==x)ans = min(ans,i+1);

            int l = i + 1;
            int r = n - 1;

            while (l <= r) {
                int m = l + (r - l) / 2;
                int rsum = suff[m];

                if (lsum + rsum == x) {
                    ans = min(ans, i + 1 + n - m);
                    break;
                }
                else if (lsum + rsum > x) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
        }

        return ans == n ? -1 : ans;
    }
};