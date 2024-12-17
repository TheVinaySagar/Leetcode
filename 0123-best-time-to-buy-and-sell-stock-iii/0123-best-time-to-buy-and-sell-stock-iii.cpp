class Solution {
public:
    int func(int ind, int n, int buy, int day, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if(ind == n || day == 0)
            return 0;
        
        int x = dp[ind][buy][day]; 
        if( x != -1) return x;
        int profit = 0;
        if(buy)
        {
            return dp[ind][buy][day] = max(-prices[ind] + func(ind +1, n, 0, day, prices,dp)
                         , 0 + func(ind +1, n, 1, day, prices,dp));
        }
            return dp[ind][buy][day] = max(prices[ind] + func(ind +1, n, 1, day-1, prices,dp)
                         , 0 + func(ind +1, n,0, day, prices,dp));
        
        
        // return dp[ind][buy][day] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3,-1)));
        return func(0, n, 1, 2, prices,dp);
    }
};