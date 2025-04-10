class Solution {
public:

    bool func(int target, vector<int> &nums, int i, int n, vector<vector<int>> &dp)
    {
        if(i > n-1)
        {
            if(target == 0)
                return true;
            else
                return false;
        }

        if(dp[i][target] != -1) return dp[i][target];
        //pick
        int pick = false; 
        if(nums[i] <= target)
            pick = func(target - nums[i], nums, i+1,n, dp);
        //notpick
        int notpick = func(target, nums, i+1,n,dp);
        return dp[i][target] = notpick || pick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2 == 1) return false;
        int half = sum/2;


        vector<vector<int>> dp(n+1, vector<int> (half+1, -1));
        return func(half, nums, 0, n, dp);
    }
};