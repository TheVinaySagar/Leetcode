class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return 0;
        int tar = sum/2;
        vector<int> prev(tar+1,false),cur(tar+1,false);
        prev[0] = cur[0] = true;
        // if()
        for(int ind = 1; ind<n;ind++ )
        {
            for(int target = 1;target<=tar;target++)
            {
                int not_take = prev[target];
                int take = false;
                if(target >= nums[ind])
                    take = prev[target - nums[ind]];
                
                cur[target] = take || not_take;
            }
            prev = cur;
        }
        
        return prev[tar];
    }
};