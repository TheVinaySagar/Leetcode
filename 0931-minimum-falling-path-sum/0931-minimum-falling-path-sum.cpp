class Solution {
public:

//     int func(vector<vector<int>> &matrix,vector<vector<int>> &dp,int i, int j)
//     {
//         if(j<0 || j>=matrix.size()) return 1e8;
//         if(i==0) return matrix[0][j];
//         if(dp[i][j] != -1) return dp[i][j];
//         int up = matrix[i][j] + func(matrix,dp, i-1, j);
//         int up_left = matrix[i][j] + func(matrix,dp, i-1, j-1);
//         int up_right = matrix[i][j] + func(matrix,dp, i-1, j+1);

//         return dp[i][j] = min(up, min(up_left,up_right));
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> dp(n,vector<int> (n,-1));
//         int maxi = 1e8;
//         for(int j=0;j<n;j++)
//             maxi = min(maxi,func(matrix, dp, n-1, j));
        

//         return maxi;
//     }
        int minFallingPathSum(vector<vector<int>> &matrix)
        {
            int n = matrix.size();
            vector<vector<int>> dp(n,vector<int> (n,-1));
            for(int j=0;j<n;j++) dp[0][j] = matrix[0][j];
            
            for(int i=1;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    int d = matrix[i][j] + dp[i-1][j];
                    
                    int d_left = matrix[i][j];
                    if(j-1>=0) d_left += dp[i-1][j-1];
                    else d_left += 1e9;
                    
                    int d_right = matrix[i][j];
                    if(j+1<n) d_right += dp[i-1][j+1];
                    else d_right += 1e9;
                    
                    dp[i][j] = min(d, min(d_left, d_right));
                }
            }
            int maxi = 1e8;
            for(int j=0;j<n;j++)
                maxi = min(maxi,dp[n-1][j]);
            return maxi;
        }
};