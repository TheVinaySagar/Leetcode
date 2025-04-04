class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        
        vector<int> prev(n+1, 0), curr(n+1,0);
        
        string t = string(s.rbegin(),s.rend());
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1]) curr[j] = 1+prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        
        
        return n-prev[n];
    }
    
    
};