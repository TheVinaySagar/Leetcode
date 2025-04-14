class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int l = 0; 
        map<char,int> mp;
        int maxi = INT_MIN;
        for(int r=0;r<n;r++)
        {
            mp[s[r]]++;

            while(mp[s[r]]>1)
            {
                mp[s[l]]--;
                l++;
                
            }
            maxi=max(maxi, r - l + 1); 
        }
        return maxi;
    }
};