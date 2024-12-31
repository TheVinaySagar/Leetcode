class Solution {
public:

    int func(int ind,int n, vector<int> &days, vector<int> &costs, vector<int> &dp)
    {
        if(ind > n-1)
            return 0;
        
        if(dp[ind] != -1) return dp[ind];
        int it = upper_bound(days.begin()+ind, days.end(), days[ind]+6) - days.begin();
        int it1 = upper_bound(days.begin()+ind, days.end(), days[ind]+29) - days.begin();
        int pass1 = costs[0] + func(ind+1,n, days, costs, dp);
        int pass2 = costs[1] + func(it,n, days, costs, dp);
        int pass3 = costs[2] + func(it1,n, days, costs, dp);

        return dp[ind] = min(pass1, min(pass2, pass3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return func(0, n, days, costs,dp);
    }
};