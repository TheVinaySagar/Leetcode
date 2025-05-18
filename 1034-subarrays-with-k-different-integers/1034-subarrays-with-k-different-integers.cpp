class Solution {
public:

    int ans(vector<int>& nums, int k)
    {
        int n = nums.size();
        int l = 0;

        int sum = 0;
        unordered_map<int,int> mp;
        for(int r=0;r<n;r++)
        {
            mp[nums[r]]++;

            while(mp.size() > k)
            {
                mp[nums[l]]--;

                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);

                l++;
            }
            sum += (r - l + 1);
        }
        return sum;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return ans(nums, k) - ans(nums, k-1);
        // int n = nums.size();
        // int l = 0;
        // unordered_map<int,int> mp;

        // for(int i=0; i<n; i++)
        // {
        //     mp[nums[i]]++;
        //     while(mp.size() > k)
        //     {
        //         cnt+=(n-i);
        //         mp[]
        //     }
        // }
    }
};