class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // int n = cardPoints.size();

        // vector<int> modified(n+2);

        // modified[0] = cardPoints[n-1];
        // modified[n+1] = cardPoints[0];

        // for(int i = 0; i < n;i++)
        //     modified[i+1] = cardPoints[i];
        
        // int l = 0;
        // int maxi = -1;
        // int sum = 0;
        // int total_elements = 0;
        // for(int r=0 ;r<n+2;r++)
        // {
        //     sum += modified[r];
        //     total_elements ++;

        //     while(total_elements > k)
        //     {
        //         total_elements --;
        //         sum -= modified[l];
        //         l++;
        //     }

        //     maxi = max(maxi, sum);
        // }
        // cout << sum <<endl;
        // return maxi;

        int n = cardPoints.size();

        int sum = 0;
        
        for(int i=0;i<k;i++)
            sum += cardPoints[i];

        
        int curr = sum;
        for(int r = k-1; r >= 0; r--)
        {
            curr -= cardPoints[r];
            curr += cardPoints[n - k + r];

            sum = max(curr, sum);
        }

        return sum;
        
    }
};