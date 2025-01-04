class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char,pair<int,int>> mp;

        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
                mp[s[i]] = {i,i};
            else
                mp[s[i]].second = i;
        }
        int cnt = 0 ;
        for(auto it:mp)
        {
            
            cout<<it.second.first<<" "<<it.second.second<<"-";
                
        }
        for(auto it:mp)
        {
            set<char> st;
            for(int i=it.second.first+1;i<it.second.second;i++)
                st.insert(s[i]);
            cnt += st.size();
            cout<<st.size()<<endl;
        }

        return cnt;
    }
};