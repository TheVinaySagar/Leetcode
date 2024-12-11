class Solution {
public:
    
    int func(int ind, vector<int> &coins, int amo, vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(amo %coins[0] == 0) return amo/coins[0];
            else return 1e9;
        }
        if(dp[ind][amo] != -1) return dp[ind][amo]; 
        int nottake = func(ind -1, coins, amo,dp);
        int take = INT_MAX;
        if(coins[ind] <= amo) take = 1 + func(ind, coins, amo-coins[ind],dp);
        
        return dp[ind][amo] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        int ans = func(n-1, coins, amount, dp);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};