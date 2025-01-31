// class Solution {
// public:
//     bool isvalid(int x, int y, int m, int n) {
//         return (x >= 0 && x < m && y >= 0 && y < n);
//     }
//     int orangesRotting(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> visited;
//         queue<pair<pair<int, int>, int>> q;
//         int cntfresh = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 2) {
//                     visited[i][j] = 2;
//                     q.push({{i, j}, 0});
//                 }
//                 else 
//                     visited[i][j] = 0;
                
//                 if(grid[i][j] == 1)
//                     cntfresh++;
//             }
//         }

//         int tm = 0;
//         int cnt = 0;
//         while (!q.empty()) {
//             vector<int> dir = {-1, 0, 1, 0, -1};
//             pair<pair<int, int>,int> curr = q.front(); q.pop();
//             int x = curr.first.first;
//             int y = curr.first.second;
//             int t = curr.second;
//             tm = max(tm, t);
//             for (int i = 0; i < 4; i++) {
//                 int x1 = x + dir[i];
//                 int y1 = y + dir[i+1];
//                 if (visited[x1][y1] == 0 && isvalid(x1, y1, m, n) &&
//                     grid[x1][y1] == 1) {
//                     q.push({{x1, y1}, t+1});
//                     visited[x1][y1] = 2;
//                 }
//             }
//             cnt ++;
//         }

//         if(cnt != cntfresh) return -1;
//         return tm;        
//     }
// };


class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        int cntfresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    visited[i][j] = 2;
                    q.push({{i, j}, 0});
                } else {
                    visited[i][j] = 0;
                }

                if (grid[i][j] == 1)
                    cntfresh++;
            }
        }

        int tm = 0;
        int rottenCount = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};

        while (!q.empty()) {
            auto [coord, t] = q.front(); q.pop();
            int x = coord.first, y = coord.second;
            tm = max(tm, t);

            for (int i = 0; i < 4; i++) {
                int x1 = x + dir[i];
                int y1 = y + dir[i+1];

                if (isValid(x1, y1, m, n) && visited[x1][y1] == 0 && grid[x1][y1] == 1) {
                    q.push({{x1, y1}, t + 1});
                    visited[x1][y1] = 2;
                    rottenCount++;
                }
            }
        }

        return (rottenCount == cntfresh) ? tm : -1;        
    }
};
