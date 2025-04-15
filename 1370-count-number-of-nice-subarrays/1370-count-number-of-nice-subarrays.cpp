class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;

        map<int,int> st;
        st[0] = 1;
        int cnt = 0;
        int ans = 0;
        for(int r = 0; r < n; r++)
        {
            if(nums[r]%2 == 1)
            {
                cnt ++;
            } 

            if(st.find(cnt - k) != st.end())
            {
                ans += st[cnt-k];
            }

            st[cnt]++;
        }

        return ans;
    }
};