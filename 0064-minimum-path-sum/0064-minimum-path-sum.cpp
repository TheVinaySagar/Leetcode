class Solution {
public:
    
//     int func(vector<vector<int>> &grid, vector<vector<int>> &dp, int m, int n)
//     {
//         if(m==0 && n==0) return grid[m][n];
//         if(m<0 || n<0) return INT_MAX;
        
//         if(dp[m][n]!=-1) return dp[m][n];
//         long long up = 1*1LL*grid[m][n] + 1*1LL*func(grid,dp, m-1,n);
//         long long left = 1*1LL*grid[m][n] + 1*1LL*func(grid,dp,m,n-1);
        
//         return dp[m][n] = min(up,left);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int> (n,-1));
//         return func(grid, dp, m-1, n-1);
        
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int> (n,-1));
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(i==0 && j==0) dp[i][j] = grid[i][j]; 
//                 else 
//                 {
//                     long long down = 1ll*grid[i][j];
//                     if(i>0) down += 1ll*dp[i-1][j];
//                     else down += 1ll*1e9;
                    
//                     long long right = 1ll*grid[i][j];
//                     if(j>0) right += 1ll*dp[i][j-1];
//                     else right += 1ll*1e9;
                    
//                     dp[i][j] = min(down, right);
//                 }
//             }
//         }
//         return dp[m-1][n-1];
//     }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n,-1);
        for(int i=0;i<m;i++)
        {
            vector<int> cur(n,-1);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0) cur[j] = grid[i][j];
                else 
                {
                    long long down = grid[i][j];
                    if(i>0) down += prev[j];
                    else down += 1e9;
                    
                    long long right = grid[i][j];
                    if(j>0) right += cur[j-1];
                    else right += 1e9;
                    
                    cur[j] = min(down, right);
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
    
    
    
    
};