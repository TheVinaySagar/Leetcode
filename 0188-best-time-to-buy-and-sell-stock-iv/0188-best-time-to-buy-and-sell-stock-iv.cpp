class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2,vector<int> (k+1,0));
        vector<vector<int>> curr(2,vector<int> (k+1,0));
        
        for(int ind = n-1;ind >= 0; ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int day=1;day<=k;day++)
                {
                    if(buy) curr[buy][day] = max(-prices[ind]+ahead[0][day], ahead[1][day]);
                    else curr[buy][day] = max(prices[ind]+ahead[1][day-1], ahead[0][day]);
                }
                
            }
            ahead = curr;
        }
        
        return ahead[1][k];
    }
};