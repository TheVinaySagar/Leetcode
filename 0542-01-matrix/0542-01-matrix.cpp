class Solution {
public:
    bool isvalid(int x, int y, int m, int n)
    {
        return (x >= 0 && x < m  && y >= 0 && y < n);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(m, vector<bool> (n,false));
        vector<vector<int>> ans(m, vector<int> (n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }


        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            ans[x][y] = dis;
            vector<int> dir = {-1,0,1,0,-1};

            for(int i=0;i<4;i++)
            {
                int x1 = x + dir[i];
                int y1 = y + dir[i+1];
                if(isvalid(x1,y1,m,n) && !vis[x1][y1])
                {
                    vis[x1][y1] = true;
                    q.push({{x1,y1}, dis+1});
                }
            }
        }

        return ans;
    }
};