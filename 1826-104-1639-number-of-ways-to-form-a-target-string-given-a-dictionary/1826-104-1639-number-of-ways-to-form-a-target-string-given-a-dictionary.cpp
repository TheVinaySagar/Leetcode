class Solution {
public:
    int MOD = 1000000007;
    #define ll long long
    
    int findTotalWays(int ind, int tpos, string target, int n, int m, int l, vector<vector<ll>> &dp, vector<vector<int>> &hash)
    {
        if(tpos == l) return ind<=m;
        if(m<=ind || (l - tpos > m - ind)) return 0;
        if(dp[ind][tpos] != -1) return dp[ind][tpos];

        ll not_take_the_char = findTotalWays(ind+1,tpos,target,n,m,l,dp,hash);
        ll take_the_colomn = findTotalWays(ind+1, tpos+1, target, n,m,l, dp, hash)%MOD;

        char ch = target[tpos];

        return dp[ind][tpos] = (not_take_the_char + take_the_colomn * (ll)hash[ind][ch-'a'])%MOD;
    }
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int m = words[0].size();
        int l = target.size();

        vector<vector<ll>> dp(m+1, vector<ll>(l+1,-1));
        vector<vector<int>> freq(m+1, vector<int> (26,0));

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                freq[j][words[i][j]-'a']++;

        return findTotalWays(0,0,target,n,m,l,dp,freq);
    }
};