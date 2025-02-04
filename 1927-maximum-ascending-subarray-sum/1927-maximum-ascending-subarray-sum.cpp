class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int maxi = 0;
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += nums[i];
            maxi = max(maxi, sum);

            if (nums[i] >= nums[i + 1])
                sum = 0;
        }

        if (nums[n - 2] < nums[n - 1]) {
            sum += nums[n - 1];
        }

        maxi = max(maxi, sum);

        return maxi;
    }
};