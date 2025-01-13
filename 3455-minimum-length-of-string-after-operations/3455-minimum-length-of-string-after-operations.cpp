class Solution {
public:
    int minimumLength(string s) {
        map<int, vector<int>> mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]-'a'].push_back(i);
        
        int ans = 0;
        for(auto &it:mp)
        {
            int n = it.second.size();
            // cout<<n<<endl;
            int n1 = n;
            while(n1 > 2)
            {
                int rem = n1%3;
                int quo = n1/3;
                n1 = rem+quo;
            }
            // cout<<n1<<endl;
            ans += n1;
        }

        return ans;
    }
};