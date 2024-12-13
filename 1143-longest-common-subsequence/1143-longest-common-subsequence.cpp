class Solution {
public:
    int func(string text1, string text2, int i, int j,vector<vector<int>> dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        
        if(dp[i][j] != -1 ) return dp[i][j];
        
        if(text1[i] == text2[j])
            return dp[i][j] = 1 + func(text1, text2, i-1, j-1,dp);
        
        return dp[i][j] = max(func(text1, text2, i-1, j,dp) , func(text1, text2,i, j-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        vector<int> prev(m+1,0), curr(m+1, 0);
        // return func(text1, text2,n , m,dp);
        // for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int j=0;j<=m;j++) prev[j] = 0;
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        
        return prev[m];
    }
};