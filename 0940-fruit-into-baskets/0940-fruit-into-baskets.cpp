class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        map<int,int> st;

        int l = -1;
        int maxi = -1;
        for(int r = 0; r<n; r++)
        {
            st[fruits[r]]=r;
            while(st.size() > 2)
            {
                int a=fruits[r];
                int b=fruits[r-1];
                int c=-1;
                for(auto it:st){
                    if(it.first!=a&&it.first!=b){
                        c=it.first;
                    }
                }
                l=st[c];
                st.erase(c);
            }
            maxi = max(maxi, r - l);
        }

        return maxi;
    }
};