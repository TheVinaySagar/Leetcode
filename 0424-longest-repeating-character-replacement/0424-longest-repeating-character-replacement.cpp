class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int maxi = 0;
        vector<int> cha(26,0);
        int maxifre = 0;
        for(int r = 0; r < n; r++)
        {
            cha[s[r] - 'A']++;
            maxifre = max(maxifre, cha[s[r]-'A']);

            while((r - l + 1) - maxifre > k)
            {
                cha[s[l] - 'A'] --;
                // maxifre = max(maxifre, cha[s[l]-'A']);
                l++;
            }
            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};