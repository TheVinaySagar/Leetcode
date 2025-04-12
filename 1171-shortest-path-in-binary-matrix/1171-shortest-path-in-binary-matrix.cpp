vector<int> dirx = {-1, 1, -1, 1, 0, 1, -1, 0};
vector<int> diry = {-1, 1, 1, -1, 1, 0, 0, -1};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // set<pair<int,pair<int,int>>> st;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> st;
        vector<vector<int>> dist(n, vector<int> (n,1e9));
        if(grid[0][0] != 0)
            return -1;

        st.push({1, {0,0}});
        dist[0][0] = 1;

        while(!st.empty())
        {
            auto to = st.top();
            int distance = to.first;
            int x = to.second.first;
            int y = to.second.second;
            st.pop();
            
            for(int i = 0; i<8 ;i++)
            {
                int nx = x + dirx[i];
                int ny = y + diry[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny]==0)
                {
                    if(distance + 1 < dist[nx][ny])
                    {
                        // st.erase({dist[nx][ny], {nx, ny}});
                        dist[nx][ny] = distance + 1;
                        st.push({dist[nx][ny],{nx,ny}});
                    }
                        
                }
            }
        }

        if(dist[n-1][n-1] == 1e9)
            return -1;
        else return dist[n-1][n-1];
    }
};