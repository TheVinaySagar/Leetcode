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
        // vector<vector<int>> dp(n+1, vector<int> (2, 0));
        vector<int> ahead(2,0), curr(2,0);
        // return func(0,n,1,prices,dp);
        ahead[0] = ahead[1] = 0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                ll profit = 0;
                if(buy)
                {
                    curr[buy] = max(-prices[ind] + ahead[0]
                                , 0 + ahead[1]);
                }
                else 
                {
                    curr[buy] = max(prices[ind] + ahead[1]
                                , 0 +ahead[0]);
                }
            }
            ahead = curr;
        }
        
        return ahead[1];
    }
};