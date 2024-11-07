class Solution {
public:
//     int func(vector<vector<int>> &tri,int i,int j)
//     {
//         if(i==tri.size()-1) return tri[tri.size()-1][j];
        
//         int down = tri[i][j] + func(tri, i+1, j);
//         int diag = tri[i][j] + func(tri, i+1, j+1);
        
//         return min(down, diag);
//     }
    
//     int func(vector<vector<int>> &tri,vector<vector<int>> dp, int i,int j)
//     {
//         if(i==tri.size()-1) return tri[tri.size()-1][j];
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int down = tri[i][j] + func(tri,dp, i+1, j);
//         int diag = tri[i][j] + func(tri,dp, i+1, j+1);
        
//         return dp[i][j] = min(down, diag);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m = triangle.size();
//         vector<vector<int>> dp(m, vector<int> (m,-1));
//         return func(triangle, dp, 0, 0);
//     }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int> (m,-1));
        for(int i=0;i<m;i++) dp[m-1][i] = triangle[m-1][i];
        
        for(int i=m-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int up = triangle[i][j] + dp[i+1][j];
                int diag  = triangle[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(up,diag);
            }
        }
        
        return dp[0][0];
    }
};