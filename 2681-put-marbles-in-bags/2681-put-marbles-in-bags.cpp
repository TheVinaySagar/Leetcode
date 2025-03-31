class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1) {
            return 0;
        }

        vector<int> ps;
        for (int i = 0; i < weights.size() - 1; ++i) {
            ps.push_back(weights[i] + weights[i + 1]);
        }

        sort(ps.begin(), ps.end());

        long long min_score =
            accumulate(ps.begin(), ps.begin() + (k - 1), 0LL);
        long long max_score =
            accumulate(ps.end() - (k - 1), ps.end(), 0LL);

        return max_score - min_score;
    }
};