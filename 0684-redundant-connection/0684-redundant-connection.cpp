class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // vector<bool> isVisited(1000,false);
        // vector<int> ans;
        // for(auto node:edges)
        // {
        //     vector<int> temp;
        //     cout<<node[0]<<" "<<node[1]<<endl;
        //     if(isVisited[node[0]] && isVisited[node[1]])
        //     {
        //         temp.push_back(node[0]);
        //         temp.push_back(node[1]);
        //         ans = temp;
        //     }
        //     else
        //     {
        //         if(!isVisited[node[0]]) isVisited[node[0]] = true;
        //         if(!isVisited[node[1]]) isVisited[node[1]] = true;
        //     }
            
        // }
        // return ans;
        int n = edges.size();
        vector<int> visited(n+1, -1);

        for(auto ed: edges)
        {
            int parentx = DFS(visited,ed[0]);
            int parenty = DFS(visited,ed[1]);

            if(parentx == parenty)
                return ed;
            else
                visited[parentx] = parenty;
        }

        return {0,0};
    }


    int DFS(vector<int> &vis, int node)
    {
        if(vis[node] == -1)
            return node;
        
        return vis[node] = DFS(vis, vis[node]);
    }
};