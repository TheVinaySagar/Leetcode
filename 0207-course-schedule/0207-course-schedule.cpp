class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n,vector<int> ());
        for(auto it:p)
            adj[it[0]].push_back(it[1]);

        vector<int> indgr(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indgr[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indgr[i] == 0)
            {
                q.push(i);
            }
        }


        int cnt=0;
        while(!q.empty())
        {
            int node = q.front(); q.pop();
            cnt++;

            for(auto it:adj[node])
            {
                indgr[it]--;
                if(indgr[it] == 0) q.push(it);
            }
        }



        return (cnt == n)?true:false;
    }
};