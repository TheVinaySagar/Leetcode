class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int n = nums.size();
        vector<int> seen; // keeps previous elements in sorted order

        for (int i = 0; i < n; ++i) {
            int lo = lower - nums[i];
            int hi = upper - nums[i];

            // count how many elements in seen are in [lo, hi]
            auto it1 = lower_bound(seen.begin(), seen.end(), lo);
            auto it2 = upper_bound(seen.begin(), seen.end(), hi);
            ans += distance(it1, it2);

            // insert current number in sorted order
            seen.insert(upper_bound(seen.begin(), seen.end(), nums[i]), nums[i]);
        }

        return ans;
    }
};
