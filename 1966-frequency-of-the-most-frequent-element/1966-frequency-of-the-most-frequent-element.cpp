class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int l = 0;
        int maxi = 1;
        for(int r = 0; r < n; r++)
        {
            sum += nums[r];
            while(1LL*(r - l + 1)*nums[r] - sum > k)
            {
                sum -= nums[l];
                l++;
            }
            maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};