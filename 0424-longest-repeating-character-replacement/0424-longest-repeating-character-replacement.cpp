class Solution {
public:
    bool func(vector<int> a, int k)
    {
        sort(a.begin(), a.end(), greater<>());
        int sum = 0;
        for(int i = 1; i < a.size(); i++)
        {
            if(a[i]==0) break;
            sum += a[i];
        }
        return sum <= k; 
    }
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int maxi = -1;
        vector<int> alpha(26,0);
        for(int r=0;r<n;r++)
        {
            alpha[s[r]-'A']++;

            while(!func(alpha, k))
            {
                alpha[s[l] - 'A']--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};