class Solution {
public:
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {   
    //     int m = obstacleGrid.size();
    //     int n = obstacleGrid[0].size();
    //     vector<vector<int>> dp(m,vector<int> (n,-1));  
        
    //     for(int i=0;i<m;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             if(i==0 && j==0 && obstacleGrid[i][j]==0) dp[i][j]=1;
    //             else if(obstacleGrid[i][j]==1) dp[i][j]=0;
    //             else
    //             {
    //                 int up(0),right(0);
    //                 if(i>0) up = dp[i-1][j];
    //                 if(j>0) right = dp[i][j-1];

    //                 dp[i][j] = up+right;
    //             }
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {   
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n,-1);  
        
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,-1);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0 && obstacleGrid[i][j]==0) temp[j]=1;
                else if(obstacleGrid[i][j]==1) temp[j]=0;
                else
                {
                    int up(0),right(0);
                    if(i>0) up = dp[j];
                    if(j>0) right = temp[j-1];

                    temp[j] = up+right;
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }

    
};