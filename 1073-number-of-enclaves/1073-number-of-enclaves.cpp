class Solution {
public:
    bool isvalid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<int>>& board) {
        vis[x][y] = 1;
        int m = vis.size();
        int n = vis[0].size();
        vector<int> dir = {-1, 0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int x1 = x + dir[i];
            int y1 = y + dir[i + 1];
            if (isvalid(x1, y1, m, n) && !vis[x1][y1] && board[x1][y1] == 1) {
                dfs(x1, y1, vis, board);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    count++;
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) &&
                    grid[i][j] == 1) {
                    dfs(i, j, vis, grid);
                }
            }
        }
        cout<<count<<endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j]) {
                    count--;
                }
            }
        }

        return count;
    }
};