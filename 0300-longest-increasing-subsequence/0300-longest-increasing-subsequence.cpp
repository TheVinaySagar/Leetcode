class Solution {
public:
    
    int func(int ind, int prev_ind, vector<int> &nums, int n, vector<vector<int>> &dp)
    {
        if(ind == n) return 0;
        
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        int con = func(ind+1, prev_ind, nums, n, dp);
        if(prev_ind == -1 || nums[ind] > nums[prev_ind])
            con = max(con,1 + func(ind+1, ind, nums, n,dp));
        
        return dp[ind][prev_ind+1] = con;
    } 
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int i=n-1;i>=0;i--)
        {
            for(int prev_ind=i-1; prev_ind>=-1; prev_ind--)
            {
                int pr = dp[i+1][prev_ind+1];
                if(prev_ind == -1 || nums[i] > nums[prev_ind])
                {
                    pr = max(pr, 1 + dp[i+1][i+1]);
                }
                dp[i][prev_ind+1] = pr;
            }
        }
        return dp[0][-1+1];
        // return func(0, -1, nums, n,dp);
    }
};