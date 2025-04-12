vector<int> dir = {-1, 0, 1, 0, -1};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            que;

        vector<vector<int>> effort(m, vector<int>(n, 1e9));
        effort[0][0] = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        que.push({0, {0, 0}});

        while (!que.empty()) {
            auto top = que.top();

            int curreffort = top.first;
            int x = top.second.first;
            int y = top.second.second;

            que.pop();
            for (int i = 0; i < 4; i++) {
                int xn = x + dir[i];
                int yn = y + dir[i + 1];

                if (xn >= 0 && xn < m && yn >= 0 && yn < n)
                {
                    int nexteffort = max(curreffort, abs(heights[xn][yn] - heights[x][y]));
                    
                    if(nexteffort < effort[xn][yn])
                    {
                        effort[xn][yn] = nexteffort;
                        // vis[xn][yn] = 1;
                        que.push({nexteffort,{xn,yn}});
                    }
                    
                }
            }
        }
        return effort[m - 1][n - 1];
    }
};