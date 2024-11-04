class Solution {
public:
    int func(vector<int> &nums )
    {
        int n = nums.size();
        int prev2 = 0;
        int prev = nums[0];
        for(int i=1; i<n; i++)
        {
            int peak = nums[i];
            if(i>1)
                peak += prev2;
            int no_pe = prev;
            
            int cur = max(peak, no_pe);
            prev2 = prev;
            prev = cur;
            
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> temp(n-1);
        vector<int> temp1(n-1);
        for(int i=0;i<n;i++)
        {
            if(i!=0) temp.push_back(nums[i]);
            if(i!=(n-1)) temp1.push_back(nums[i]);
        }
        return max(func(temp), func(temp1));
        
    }
};