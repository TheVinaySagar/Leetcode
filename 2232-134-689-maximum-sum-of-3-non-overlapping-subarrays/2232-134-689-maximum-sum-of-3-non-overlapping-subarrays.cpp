class Solution {
public:
    int findMaxSum(int ind, int cnt, int k, int n, vector<int> &prefix, vector<vector<int>> &dp)
    {

        if(cnt == 3) return 0;
        if(ind>n-k) return 0;
        if(dp[ind][cnt] != -1) return dp[ind][cnt];
        // when not take the element;
        int nottake = findMaxSum(ind+1, cnt, k, n, prefix, dp);
        // when take the element;
        int take = findMaxSum(ind+k, cnt+1, k, n, prefix, dp)
                    + prefix[ind+k] - prefix[ind];

        return dp[ind][cnt] = max(take, nottake);
    }

    void findMaxPath(int ind, int cnt, int k, int n, vector<int> &path, vector<int> &prefix,vector<vector<int>> &dp)
    {
        if(cnt == 3) return;
        if(ind > n - k) return;

        int notake = findMaxSum(ind+1, cnt, k, n, prefix, dp);
        int take = findMaxSum(ind+k, cnt+1, k, n, prefix, dp)
                    + prefix[ind+k] - prefix[ind];

        if(take >= notake)
        {
            path.push_back(ind);
            findMaxPath(ind+k,cnt+1,k,n,path,prefix,dp);
        }
        else findMaxPath(ind+1,cnt,k,n,path,prefix,dp);
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n+1,0);
        vector<vector<int>> dp(n+1, vector<int> (3, -1));
        vector<int> path;
        for(int i=0;i<n;i++)
            prefixSum[i+1] = prefixSum[i]+nums[i];
       
        findMaxPath(0,0,k,n,path,prefixSum,dp);
        return path;
    }
};