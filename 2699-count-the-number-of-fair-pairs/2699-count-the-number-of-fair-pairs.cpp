class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            auto up = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]);
            auto down = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i]);
            ans += distance(up, down);
        }
        return ans;
    }
};