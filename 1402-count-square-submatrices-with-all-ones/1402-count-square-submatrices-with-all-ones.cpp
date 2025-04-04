class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 1){
                    int mn=min(dp[i+1][j],min(dp[i][j],dp[i][j+1]));
                    dp[i+1][j+1]=1+mn;
                    ans+=dp[i+1][j+1];
                }
            }
        }
        return ans;
    }
};