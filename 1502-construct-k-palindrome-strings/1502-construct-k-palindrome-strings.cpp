class Solution {
public:
    bool canConstruct(string s, int k) {

        if(s.size() < k) return false;
        unordered_map<char,int> mp;

        for(auto it:s)
            mp[it]++;

        int even(0), odd(0);
        for(auto &it:mp)
        {
            if(it.second%2==0) even++;
            else odd++;
        }
        
        return odd<=k;
    }
};