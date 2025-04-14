class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l = 0;
        int zero = 0;
        int one = 0;
        int maxi = INT_MIN;
        for(int r = 0; r < n; r++)
        {
            if(nums[r] == 0) zero++;
            if(nums[r] == 1) one++;

            while(zero > k)
            {
                if(nums[l] == 0)
                    zero--;
                l++;
            }
            maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};