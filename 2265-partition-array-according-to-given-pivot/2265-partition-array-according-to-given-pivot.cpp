class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int i = -1;

        map<int, int> mp1;
        map<int, int> mp2;

        for(int i=0;i<n;i++)
        {
            if(nums[i] < pivot)
                mp1[i] = nums[i];
            else if(nums[i] > pivot)
                mp2[i] = nums[i];
        }

        vector<int> ans;

        for(auto &it:mp1)
        {
            ans.push_back(it.second);
        }
        for(auto &it:nums)
        {
            if(it == pivot)
                ans.push_back(it);
        }
        for(auto &it:mp2)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};