class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int maxi = INT_MAX;
        int n = blocks.size();

        for(int i=0;i<=n-k;i++)
        {
            int no_of_W =  0;
            for(int j=0;j<k;j++)
            {
                if(blocks[i+j]=='W')
                {
                    no_of_W++;
                }
            }
            maxi = min(maxi, no_of_W);
        }

        return maxi;


    }
};