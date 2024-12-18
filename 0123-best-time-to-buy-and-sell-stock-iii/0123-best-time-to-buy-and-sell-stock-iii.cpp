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
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,0)));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<=1;j++)
                dp[i][j][0] = 0;
        
        for(int i=0;i<=1;i++)
            for(int j=0;j<=2;j++)
                dp[n][i][j] = 0;
            
        for(int ind=n-1;ind>=0;--ind)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int days=1;days<=2;days++)
                {
                    if(buy) dp[ind][buy][days] = max(-prices[ind]+dp[ind+1][0][days], dp[ind+1][1][days]);
                    else dp[ind][buy][days] = max(prices[ind]+dp[ind+1][1][days-1], dp[ind+1][0][days]);
                }
            }
        }
        
        return dp[0][1][2];
    }
};