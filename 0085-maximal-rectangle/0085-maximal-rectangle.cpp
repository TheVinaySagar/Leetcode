class Solution {
public:

    int maxr(vector<int> &hist)
    {
        int n = hist.size();
        stack<int> sta;
        int maxi = 0;
        for(int i = 0 ; i<=n ; i++)
        {
            while(!sta.empty() && (i==n || hist[i] <= hist[sta.top()]))
            {
                int height = hist[sta.top()];
                sta.pop();

                int weight;
                if(sta.empty())
                    weight = i ;
                else
                    weight = i - sta.top() - 1;

                maxi = max(maxi, height*weight);   
            }
            sta.push(i);
        }

        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> hist(cols,0);
        int maxi = 0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(matrix[i][j] == '0')
                    hist[j] = 0;
                else
                    hist[j] ++;
            }
            maxi = max(maxi, maxr(hist));
        }
        return maxi;
    }
};