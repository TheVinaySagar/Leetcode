class Solution {
public:
    #define ll long long 
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxpre(n, 0);
        int maxi = nums[n - 1];
        maxpre[n - 1] = maxi;
        for (int i = n - 2; i >= 0; i--) {
            maxi = max(maxi, nums[i]);
            maxpre[i] = maxi;
        }
        int first = nums[0];
        ll maxi1 = 0;
        for (int i = 1; i < n - 1; i++) {
            maxi1 = max(maxi1, 1LL*(1LL*(first - nums[i]) * maxpre[i + 1]));
            
            first = max(first, nums[i]);
        }

        return maxi1 < 0 ? 0 : maxi1;
    }
};