class Solution {
public:
    bool checkthestring(string s, string t)
    {
        if(s.size() != 1 + t.size()) return false;
        int n = s.size();
        int m = t.size();
        int i(0),j(0);
        while (i < n)
        {
            if(s[i] == t[j])
            {
                i++;
                j++;
            }
            else
                i++;

        }
        
        if(i == n && j == m) return true;
        return false;
    }
    
    bool comp(string &s1,string &s2)
    {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();  // example comparison
        });
        for(auto it:words) cout<<it<<" ";
        int n = words.size();
        vector<int> dp(n+1, 1);
        int maxi = 1;
        for(int ind=0;ind<n;ind++)
        {
            for(int prev=0;prev<ind;prev++)
                if(checkthestring(words[ind], words[prev]))
                    dp[ind] = max(dp[ind],dp[prev] +1);
            maxi = max(maxi, dp[ind]);
        }
        return maxi;
    }
};