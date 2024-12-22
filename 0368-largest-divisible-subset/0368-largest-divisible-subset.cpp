class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, 1);
        int last_ind = 0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            hash[i] = i;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0 && dp[i] < 1 + dp[j])
                {
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                last_ind = i;
            }
        }
        
        
        vector<int> temp;
        temp.push_back(arr[last_ind]);
        
        while(hash[last_ind] != last_ind)
        {
            last_ind = hash[last_ind];
            temp.push_back(arr[last_ind]);
        }
        
        
        reverse(temp.begin(), temp.end());
        return temp;
        // for(int dp:temp)
        //     cout<<dp<<" ";
    }
};