class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        map<int, multiset<int, greater<int>>> mp;

        for(int i=0;i<n;i++)
        {
            int a = nums[i];
            int su = 0;
            while(a > 0)
            {
                int rem = a % 10;
                su += rem;
                a = a / 10;
            }

            mp[su].insert(nums[i]);
        }

        // for (const auto& it : mp) {
        //     cout << "Sum: " << it.first << " -> ";
        //     for (int num : it.second) {
        //         cout << num << " ";
        //     }
        //     cout << endl;
        // }

        int maxi = -1;
        for(auto &it:mp)
        {
            if(it.second.size() >= 2)
                maxi = max(maxi,*it.second.begin() + *(++it.second.begin()));
        }

        return maxi;
        
    }
};