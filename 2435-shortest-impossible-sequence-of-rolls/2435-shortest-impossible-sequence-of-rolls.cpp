class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n = rolls.size();

        int k1 = 1;
        int len = 0;
        set<int> st;
        for(int i=0;i<n;i++)
        {
            st.insert(rolls[i]);
            if(st.size() == k)
            {
                len++;
                st.clear();
            }
        }
        return len+1;
    }
};