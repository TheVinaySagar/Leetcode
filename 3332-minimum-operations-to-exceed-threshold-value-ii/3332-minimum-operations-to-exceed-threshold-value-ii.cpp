class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long> st;
        int n = nums.size();
        for(int i =0;i<n;i++)
            st.insert(nums[i]);

        int cnt = 0;
        while(st.size() >= 2 && *st.begin()<k)
        {
            auto f = st.begin();
            auto s = next(f);


            long long fi = *f;
            long long se = *s;

            st.erase(f);
            st.erase(s);

            st.insert(1LL*(fi*2 + se));
            cnt ++;
        }        

        return cnt;
    }
};