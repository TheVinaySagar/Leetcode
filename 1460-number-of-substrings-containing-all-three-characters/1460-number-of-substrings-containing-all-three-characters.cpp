class Solution {
public:

    bool check(vector<int> &freq)
    {
        return (freq[0] > 0 && freq[1] > 0 && freq[2] > 0);
    }
    int numberOfSubstrings(string s) {
        int n = s.size();
        
        int l = 0;
        int r = 0;
        vector<int> freq(3,0);
        int total = 0;
        while(r < n)
        {
            char curr = s[r];
            freq[curr - 'a'] ++;

            while(check(freq))
            {
                total += n - r;

                char leftchar = s[l];
                freq[leftchar - 'a'] --;
                l++;
            }

            r++;
        }

        return total;
    }
};