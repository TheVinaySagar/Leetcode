class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        int mini = INT_MAX;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum + nums[i];
            maxi = max(sum, maxi);

            if(sum < 0) sum = 0;
        }

        int sum1 = 0;
        for(int i=0;i<n;i++)
        {
            sum1 += nums[i];
            mini = min(sum1, mini);

            sum1 = min(sum1, 0);
        }
        cout<<maxi<<": "<<mini<<endl;
        return max(abs(maxi), abs(mini));
    }
};