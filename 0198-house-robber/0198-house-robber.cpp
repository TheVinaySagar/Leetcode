class Solution {
public:
    // Memorisation
    // int func(vector<int> arr, int ind,vector<int> dp)
    // {
    //     if(ind == 0) return arr[ind];
    //     if(ind < 0) return 0;

    //     if(dp[ind] != -1) return dp[ind];

    //     int pick = arr[ind] + func(arr, ind-2,dp );
    //     int non_pick = func(arr, ind-1,dp);

    //     return dp[ind] = max(pick, non_pick);
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n,-1);

    //     for()
    //     return func(nums, n-1, dp);
        
    // }
        // Tabulation
        int rob(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> dp(n,-1);
            dp[0] = nums[0];

            for(int i=1;i<n;i++)
            {
                int peak = nums[i];
                if(i > 1) peak += dp[i-2];
                int non_peak = dp[i-1];

                dp[i] = max(peak, non_peak);
            }       
            return dp[n-1];
        }

//         int rob(vector<int> nums)
//         {
//             int n = nums.size();
            
//         }
};