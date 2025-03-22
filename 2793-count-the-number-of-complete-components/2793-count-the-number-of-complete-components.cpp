class Solution {
public:
    void dfs(vector<int> &vis,vector<int> adj[],int node,vector<int> &comp){
        comp.push_back(node);
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(vis,adj,it,comp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n+1];
        for(int i=0;i<edges.size();i++){
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                vector<int> comp;
                dfs(vis,adj,i,comp);
                int c=0;
                for(auto it:comp){
                    if(adj[it].size() != comp.size()-1){
                        c=1;break;
                    }
                }
                if(c==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};