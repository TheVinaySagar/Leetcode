// class Solution {
// public:
// #define pip pair<int, pair<int, int>>
//     vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
//         queue<pip> q;
//         q.push({isWater[0][0], {0, 0}});
//         int m = isWater.size();
//         int n = isWater[0].size();
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
//         vector<vector<int>> ans(m, vector<int>(n, 1));
//         visited[0][0] = false;
//         vector<int> map = {-1, 0, 1, 0, -1};
//         while (!q.empty()) {
//             pip curr = q.front();
//             q.pop();

//             int val = curr.first;
//             int x = curr.second.first;
//             int y = curr.second.second;
//             int flag = 0;
//             for (int i = 0; i < 4; i++) {
//                 int xn = x + map[i];
//                 int yn = x + map[i + 1];
//                 if (xn >= 0 && xn < m && yn >= 0 && yn < n &&
//                     !visited[xn][yn]) {

//                     q.push({isWater[xn][yn], {xn, yn}});
//                     visited[xn][yn] = 1;
//                     if (isWater[xn][yn] == 1)
//                         flag = 1;
//                 }
//             }
//             if(isWater[x][y] != 1)
//                 (flag==0)?ans[x][y]=2:ans[x][y]=1;
//             else
//                 ans[x][y]=0;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int r=isWater.size(), c=isWater[0].size();
        const int d[5]={0, 1, 0, -1, 0};
        vector<vector<int>> H(r, vector<int>(c, -1));
        queue<int> q;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if (isWater[i][j]){
                    int idx=(i<<10)+j;
                    H[i][j]=0;
                    q.push(idx);
                }
            }
        }
        for(int h=0; !q.empty(); h++){
            int qz=q.size();
            for(int a=0; a<qz; a++){
                int idx=q.front(), i=idx>>10, j=idx&((1<<10)-1);
                q.pop();
                for(int b=0; b<4; b++){
                    int s=i+d[b], t=j+d[b+1];
                    if (s<0||s>=r||t<0||t>=c|| H[s][t]!=-1) continue;
                    q.push((s<<10)+t);
                    H[s][t]=h+1;
                }
            }
        }
        return H;
    }
};