class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        map<int,int> st;

        int l = 0;
        int maxi = -1;
        for(int r = 0; r<n; r++)
        {
            st[fruits[r]]++;
            while(st.size() > 2)
            {
                st[fruits[l]]--;
                if(st[fruits[l]] == 0)
                    st.erase(fruits[l]);
                
                l++;
            }
            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};