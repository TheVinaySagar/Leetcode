class Solution {
public:   
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        // vector<int> maxLeftScore(n);
        int maxLeftScore = values[0];

        int maxScore = 0;

        for(int i=1;i<n;i++)
        {
            int currRight = values[i]-i;
            maxScore = max(maxScore, maxLeftScore+currRight);
            int currleft = values[i]+i;
            maxLeftScore = max(maxLeftScore, currleft);
        }        
        return maxScore;
    }
};