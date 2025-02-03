class Solution {
public:

    int isValid(int x,int y, int m, int n)
    {
        return (x>=0 and x<m and y>=0 and y<n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int in_c = image[sr][sc];
        image[sr][sc] = color;
        vis[sr][sc] = 1;

        vector<int> dir = {-1,0,1,0,-1};

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int xn = x + dir[i];
                int yn = y + dir[i+1];

                if(isValid(xn, yn, m, n) && image[xn][yn] == in_c && !vis[xn][yn])
                {
                    image[xn][yn] = color;
                    vis[xn][yn] = 1;
                    q.push({xn, yn});
                }
            }
        }


        return image;
    }
};