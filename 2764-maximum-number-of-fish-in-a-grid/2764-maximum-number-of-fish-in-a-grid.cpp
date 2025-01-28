class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    bool isvalid(int i, int j, int n, int m)
    {
        return (i < n && j < m && i>=0 && j >=0);
    }

    int dfs(vector<vector<int>>  &grid, vector<vector<int>> &visited, int &n, int m, int x, int y)
    {
        int fishs = grid[x][y];


        for(int i=0;i<4;i++)
        {
            int x1 = x + dir[i];
            int y1 = y + dir[i+1];

            if(isvalid(x1, y1, n, m) && !visited[x1][y1] && grid[x1][y1]>0)
            {
                visited[x1][y1] = 1;
                fishs += dfs(grid, visited, n, m, x1,y1);
            }
        }

        return fishs;
    }
         
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int> (m, 0));
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j] > 0)
                {
                    visited[i][j] = 1;
                    maxi = max(maxi, dfs(grid, visited, n, m, i, j));
                }
            }
        }

        return maxi;
    }
};