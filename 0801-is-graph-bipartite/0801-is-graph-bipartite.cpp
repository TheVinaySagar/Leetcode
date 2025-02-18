class Solution {
public:

    bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &adj)
    {
        color[node] = col;

        for(auto child:adj[node]){
            if(color[child] == -1)
            {
                if(dfs(child, !col, color, adj) == false) return false;
            }
            else if(color[child] == col)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
        int n = graph[0].size();

        vector<vector<int>> vis(m, vector<int> (n,0));
        vector<int> colored(m+1,-1);

        for(int i=0;i<m;i++)
        {
            if(colored[i] == -1)
            {
                if(dfs(i,0,colored,graph) == false) return false;
            }
        }
        return true;
    }

};