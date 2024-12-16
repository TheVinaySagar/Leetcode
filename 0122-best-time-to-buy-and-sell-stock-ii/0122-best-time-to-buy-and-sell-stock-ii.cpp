#define ll long long

class Solution {
public:
    
    int func(ll ind, ll n, ll buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if(ind == n) return 0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        ll profit = 0;
        if(buy)
        {
            profit = max(-prices[ind] + func(ind + 1, n, 0, prices, dp)
                        , 0 + func(ind + 1, n, 1, prices, dp));
        }
        else 
        {
            profit = max(prices[ind] + func(ind + 1, n, 1, prices, dp)
                        , 0 + func(ind + 1, n, 0, prices, dp));
        }
        
        return dp[ind][buy] = profit;
            
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, -1));
        return func(0,n,1,prices,dp);
    }
};