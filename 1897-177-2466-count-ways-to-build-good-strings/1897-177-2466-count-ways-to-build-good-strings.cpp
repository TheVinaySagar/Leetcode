class Solution {
public:
    int MOD = 1000000007;
    int func(int zero, int one, int count, int low, int high, vector<int> &dp)
    {
        if(count>high) return 0;
        if(dp[count] != -1) return dp[count];
        int zerolen = count+zero;
        int onelen = count+one;
        int z = (zerolen >= low && zerolen<=high)?1:0;
        int o = (onelen >= low && onelen<=high)?1:0;
        int take_zero = (z + func(zero, one , zerolen, low, high,dp))%MOD;
        int take_one = (o + func(zero,one,onelen,low,high,dp))%MOD;

        return dp[count] = (take_zero + take_one)%MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+max(one,zero), -1);
        return func(zero, one,0, low,high,dp);
    }
};