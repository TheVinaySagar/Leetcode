class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = arr.size();
        int a = mat.size();
        int b = mat[0].size();


        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]] = i; 
        }

        int minx = INT_MAX;
        for(int i=0;i<a;i++)
        {
            int lminx =INT_MIN;
            for(int j=0;j<b;j++)
            {
                lminx = max(lminx, mp[mat[i][j]]);
            }
            minx = min(minx, lminx);
        }


        int miny = INT_MAX;
        for(int i=0;i<b;i++)
        {
            int lminy = INT_MIN;
            for(int j=0;j<a;j++)
            {
                lminy = max(lminy, mp[mat[j][i]]);
            }
            miny = min(miny, lminy);
        }

        return min(miny, minx);
    }
};