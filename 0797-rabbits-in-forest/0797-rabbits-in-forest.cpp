class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        map<int, int> mp;
        for(const auto &it : answers)
            mp[it]++;
        
        int ans = 0;
        for(auto &it : mp)
        {
            ans += ceil((double)it.second / (it.first + 1)) * (it.first + 1);
        }
        return ans;
    }
};