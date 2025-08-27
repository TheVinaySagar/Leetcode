class Solution {
public:
    vector<int> pos = {-1, 0, 1, 0, -1};
    int n, m;
    bool boundary(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < m); }

    int cnt = 0;
    void dfs(vector<vector<int>>& vis, vector<vector<char>>& grid, int x,
             int y) {
        vis[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int xn = pos[i] + x;
            int yn = pos[i + 1] + y;
            if (boundary(xn, yn) && !vis[xn][yn] && grid[xn][yn] == '1') {
                dfs(vis, grid, xn, yn);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    cout<<"JAA"<<endl;
                    dfs(vis, grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};