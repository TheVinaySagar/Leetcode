class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)
        {
            return 1;
        }
        long long x=1;
        for(int i=1;i<n;i++)
        {
            x+=(i*4);
        }
        return x;
    }
};