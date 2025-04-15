class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        map<int,int> mp;
        mp[0] = 1;
        int ans = 0;
        int ones = 0;
        for(int r = 0;r < n; r++)
        {
            if(nums[r] == 1) ones++;
            if(mp.find(ones - goal) != mp.end())
            {
                ans += mp[ones-goal];
            }

            mp[ones]++;
        }

        return ans;
    }
};