class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
        }

        vector<int> ans;
        for(auto it : nums)
        {
            if(it != 0) ans.push_back(it);
        }

        int siz = ans.size();
        for(int i=siz;i<n;i++)
        {
            ans.push_back(0);
        }
        
        return ans;
    }
};