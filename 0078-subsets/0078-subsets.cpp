class Solution {
public:
    
    void func(int ind, int n, vector<int> &dp, vector<int> &a, vector<vector<int>> &res)
    {
        if(ind == n)
        {
            res.push_back(dp);
            return;
        }
        
        func(ind+1, n, dp, a, res);
        dp.push_back(a[ind]);
        func(ind+1, n, dp, a, res);
        dp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        vector<vector<int>> res;
        
        func(0, n , dp, nums, res);
        
        return res;
        // cout<<'[';
        // for(auto it:res)
        // {
        //     cout<<'[';
        //     for(auto i:it)
        //     {
        //         cout<<i<<",";
        //     }
        //     cout<<']';
        // }
        // cout<<']';
    }
};