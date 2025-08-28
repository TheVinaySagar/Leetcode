class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int,int> mp;

        stack<int> sta;
        vector<int> ans;
        for(int i = m-1; i>=0; i--)
        {
            while(!sta.empty() && sta.top() < nums2[i])
                sta.pop();
            
            if(sta.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = sta.top();

            sta.push(nums2[i]);
        }
        
        for(int i = 0; i< n; i++)
        {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};