class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k){
        for(int i =0 ;i<k-1;i++)
        {
            colors.push_back(colors[i]);
        }

        int length = colors.size();
        int ans = 0;

        int l = 0;
        int r = 1;

        while(r < length)
        {
            if(colors[r] == colors[r-1])
            {
                l = r;
                r ++;
                continue;
            }

            r++;

            if(r - l < k) continue;

            ans++;
            l++; 
        }

        return ans;
    }
};