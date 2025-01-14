class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        set<int> st;
        vector<int> ans;
        for(int i=0;i<A.size();i++)
        {
            st.insert(A[i]);
            st.insert(B[i]);

            int comm = 2*i+2;
            ans.push_back(comm - st.size());
        }
        return ans;
    }
};