class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        map<int,int> mp;
        mp[0] = 1;
        int pr = 0;
        int cnt = 0;
        for(int i =0;i<n;i++)
        {
            pr += nums[i];
            
            if(mp.find(pr-k) != mp.end())
            {
                cnt += mp[pr-k];
            }
            mp[pr] ++;
        }

        return cnt;
    }
};