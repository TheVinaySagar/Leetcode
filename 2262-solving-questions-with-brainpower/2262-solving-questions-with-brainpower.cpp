class Solution {
public:
    #define ll long long

    ll func(vector<vector<int>> &que, int i, vector<ll> &dp)
    {
        if(i >= que.size())
            return 0;
        // nottake 

        if(dp[i] != -1) return dp[i];
        ll nottake = func(que, i + 1, dp);
        
        // take
        ll take = que[i][0] + func(que, i + que[i][1]+1, dp);

        return dp[i] = max(take, nottake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n+1, 0);

        dp[n-1] = questions[n-1][0];
        for(int i =n-2; i>=0 ;i--)
        {
            ll take = 0;
            ll val = questions[i][0];
            ll pos = questions[i][1];
            if(i+pos+1 < n) take = dp[i+pos+1];
            dp[i] = max(dp[i+1], val + take);
        }

        return dp[0];

        // return func(questions, 0, dp);
    }
};