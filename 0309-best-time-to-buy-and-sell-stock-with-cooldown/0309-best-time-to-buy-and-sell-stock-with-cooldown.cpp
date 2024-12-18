#define ll long long

class Solution {
public:
    
    int func(ll ind, ll n, ll buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if(ind >= n) return 0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        ll profit = 0;
        if(buy)
        {
            profit = max(-prices[ind] + func(ind + 1, n, 0, prices, dp)
                        , 0 + func(ind + 1, n, 1, prices, dp));
        }
        else 
        {
            profit = max(prices[ind] + func(ind + 2, n, 1, prices, dp)
                        , 0 + func(ind + 1, n, 0, prices, dp));
        }
        
        return dp[ind][buy] = profit;
            
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int> (2, -1));
        vector<int> front2(2, 0);
        vector<int> front1(2, 0);
        vector<int> curr(2, 0);
        
        for(int ind=n-1;ind>=0;ind--)
        {
            curr[1] = max(-prices[ind]+front1[0], front1[1]);
            curr[0] = max(prices[ind] + front2[1], front1[0]);
            
            front2 = front1;
            front1 = curr;
        }
        
        return curr[1];
        // return func(0,n,1,prices,dp);
    }
};