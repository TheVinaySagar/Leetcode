class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        
        long long all_good = 0;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(mp.count(nums[i] - i))
                all_good += mp[nums[i] - i];
            
            mp[nums[i] - i]++;
        }
        
        long long ans = 1LL * n*(n-1)/2 - all_good;
        return ans;
    }
};