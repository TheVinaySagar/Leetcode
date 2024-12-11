class Solution {
public:
    int findTargetSumWays(vector<int>& a, int d) {
//         int n = nums.size();
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if((sum - target) < 0 || (sum - target)%2 == 1) return 0;
//         int tar = (sum-target)/2;
//         vector<int> prev(tar+1, 0);
//         for(int i=0;i<=tar;i++)
//         {
//             if(i==0 && nums[0]==0) prev[i] = 2;
//             else if(i==0 || nums[0]==i) prev[i] = 1;
//             else prev[i] = 0;
//         }
        
//         for(int ind = 1;ind < n; ind ++)
//         {
//             vector<int> curr(tar+1, 0);
//             for(int T = 0;T<=tar;T++)
//             {
//                 int ntake = prev[T];
//                 int take = 0;
//                 if(nums[ind ] <= tar) take =  prev[T-nums[ind]];
                
                
//                 curr[tar] =  take + ntake;
//             }
//             prev = curr;
//         }
        
//         return prev[tar];
        int n = a.size();
        int sum = accumulate(a.begin(),a.end(),0);
        if((sum - d)%2 || (sum-d)<0 ) return 0;
        int target = (sum-d)/2;
        vector<int> prev(target + 1, 0);
        
        for(int i=0;i<=target;i++)
        {
            if(i==0 && a[0]==0) prev[i] = 2;
            else if(i==0 || a[0]==i) prev[i] = 1;
            else prev[i] = 0;
        }
        
        for(int ind = 1;ind<n;ind++)
        {
            vector<int> curr(target+1,0);
            for(int tar=0;tar<=target;tar++)
            {
                int ntake = prev[tar];
                int take = 0;
                if(a[ind] <= tar)
                {
                    take = prev[tar-a[ind]];
                }
                
                curr[tar] = take + ntake;
            }
            
            prev = curr;
        }
        
        return prev[target];
        
    }
};