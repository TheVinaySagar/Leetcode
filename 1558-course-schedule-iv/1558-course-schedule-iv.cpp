class Solution {
public:
    #define maxi 10000
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>> distan(n, vector<int> (n, maxi));

        for(int i=0;i<n;i++)
            distan[i][i] = 0;

        unordered_map<int,vector<int>> adj;
        for(auto edge:prerequisites)
        {
            adj[edge[0]].push_back(edge[1]);
            distan[edge[0]][edge[1]] = 1;
        }

        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(distan[i][j] > distan[i][k]+distan[k][j])
                        distan[i][j] = distan[i][k]+distan[k][j];
        

        vector<bool> ans;
        for(auto query:queries)
            if(distan[query[0]][query[1]] < maxi)
                ans.push_back(true);
            else   
                ans.push_back(false);
            
        return ans;
    }
};