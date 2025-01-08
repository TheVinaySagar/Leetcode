class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> dp(n, 1e9);
        int ans = 0;
        dp[0] = prices[0];
        for(int i=1;i<n;i++)
        {
            dp[i] = min(dp[i-1], prices[i]);
            ans = max(ans, prices[i]-dp[i]);
        }

        return ans;
    }
};