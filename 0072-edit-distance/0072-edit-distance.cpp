class Solution {
public:
    
    int func(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if(j==0) return i;
        if(i==0) return j;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        if(s[i-1] == t[j-1])
            return dp[i][j] = 0 + func(i-1, j-1, s, t, dp);
        else    
            return dp[i][j] = min(1 + func(i, j-1, s,t,dp), // insert the character
                                 min(1 + func(i-1, j, s,t, dp), // delete the character
                                 1 + func(i-1, j-1,s, t, dp))); // Replace the character
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        vector<int> prev(m+1, 0), curr(m+1,0);        
        for(int j=0;j<=m;j++) prev[j] = j;
        for(int i = 1;i<=n;i++)
        {
            curr[0] = i;
            for(int j=1;j<=m; j++)
            {
                if(word1[i-1] == word2[j-1])
                    curr[j] = prev[j-1];
                else    
                    curr[j] = 1 + min(curr[j-1], min(prev[j], prev[j-1]));
            }
            prev = curr;
        }
        return prev[m];
        // return func(n, m, word1, word2, dp);
    }
};