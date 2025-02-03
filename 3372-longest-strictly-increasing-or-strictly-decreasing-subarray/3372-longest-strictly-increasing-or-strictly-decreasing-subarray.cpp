class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt = 0;

        int n = nums.size();
        int lcl_cnt = 0;
        int lcl_cnt1 = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                lcl_cnt++;
                lcl_cnt1 = 0;
            } else if (nums[i] > nums[i + 1]) {
                lcl_cnt1++;
                lcl_cnt = 0;
            } else {
                lcl_cnt = 0;
                lcl_cnt1 = 0;
            };

            cnt = max(cnt, max(lcl_cnt, lcl_cnt1));
        }

        return cnt+1;
    }
};