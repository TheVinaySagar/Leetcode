class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseG(n);

        for(int i =0 ;i<n ;i++)
            for(auto &it:graph[i])
                reverseG[it].push_back(i);
        vector<int> outdegree(n,0);
        for(auto &it:reverseG)
            for(auto &it1 : it)
                outdegree[it1]++;
        
        queue<int> q;

        for(int i =0;i<n;i++)
        {
            if(outdegree[i]== 0)
                q.push(i);            
        }
        vector<int> res;
        while(!q.empty())
        {
            int curr = q.front();
            res.push_back(curr);
            q.pop();

            for(auto &it:reverseG[curr])
            {
                outdegree[it]--;
                if(outdegree[it] == 0) 
                {
                    q.push(it);
                }
            }

        }
        sort(res.begin(), res.end());
        return res;
    }
};