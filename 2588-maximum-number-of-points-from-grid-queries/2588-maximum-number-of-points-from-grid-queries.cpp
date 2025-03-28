class Solution {
public:
    bool isvalid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int qs = queries.size();

        priority_queue < pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>, greater<> > q;
        vector<pair<int, int>> sortedQue;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<int> ans(qs,0);

        for (int i = 0; i < qs; i++)
            sortedQue.push_back({queries[i], i});

        sort(sortedQue.begin(), sortedQue.end());

        
        int to = 0;
        q.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        
        for (auto [ele1,pos]:sortedQue) {
            while (!q.empty() && ele1 > q.top().first) {
                int x = q.top().second.first;
                int y = q.top().second.second;
                q.pop();
                to++;
                vector<int> dir = {-1, 0, 1, 0, -1};
                for (int d = 0; d < 4; d++) {
                    int dx = x + dir[d];
                    int dy = y + dir[d + 1];

                    if (isvalid(dx, dy, m, n) && !vis[dx][dy]) {
                        q.push({grid[dx][dy], {dx, dy}});
                        vis[dx][dy] = 1;
                    }
                }
            }
            ans[pos] = to;
        }
        return ans;
    }
};