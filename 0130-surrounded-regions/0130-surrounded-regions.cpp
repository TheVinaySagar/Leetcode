class Solution {
public:
    bool isvalid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    void dfs(int x, int y, vector<vector<int>>& vis,
             vector<vector<int>>& checked, vector<vector<char>>& board) {
        vis[x][y] = 1;
        int m = vis.size();
        int n = vis[0].size();
        vector<int> dir = {-1, 0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int x1 = x + dir[i];
            int y1 = y + dir[i + 1];
            if (isvalid(x1, y1, m, n) && !vis[x1][y1] && board[x1][y1] == 'O') {
                dfs(x1, y1, vis, checked, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> checked(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) &&
                    board[i][j] == 'O') {
                    dfs(i, j, vis, checked, board);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};