class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        // vector<vector<int>> adj(n,vector<int> ());
        vector<int> adj[n];
        for(auto it:p)
            adj[it[0]].push_back(it[1]);
        
        vector<int> indgr(n,0);
        for(int i=0;i<n;i++)
            for(auto it:adj[i])
                indgr[it]++;

        queue<int> q;
        for(int i=0;i<n;i++)
            if(indgr[i]==0)
                q.push(i);

        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node])
            {
                indgr[it]--;
                if(indgr[it] == 0) q.push(it);
            }
        }
        reverse(ans.begin(), ans.end());
        vector<int> a = {};
        return  (ans.size()==n) ? ans : a;
    }
};