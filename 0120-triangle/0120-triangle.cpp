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
        vector<int> prev(m,-1);
        for(int i=0;i<m;i++) prev[i] = triangle[m-1][i];
        
        for(int i=m-2;i>=0;i--)
        {
            vector<int> cur(m,-1);
            for(int j=i;j>=0;j--)
            {
                int up = triangle[i][j] + prev[j+1];
                int diag  = triangle[i][j] + prev[j];
                
                cur[j] = min(up,diag);
            }
            prev = cur;
        }
        
        return prev[0];
    }
};