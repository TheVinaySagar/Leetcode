class Solution {
public:
    string minRemoveToMakeValid(string s) {
        ios::sync_with_stdio(0);
    cin.tie(0);
        int openCount = 0;
        int removals = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++openCount;
            } else if (s[i] == ')') {
                if (openCount == 0) {
                    s[i] = '*'; 
                    ++removals;
                } else {
                    --openCount;
                }
            }
        }

        int i = s.size() - 1;
        while (openCount > 0 && i >= 0) {
            if (s[i] == '(') {
                s[i] = '*'; 
                --openCount;
                ++removals;
            }
            --i;
        }

        string result;
        for (int i=0; i<s.length(); i++) 
        {
            char c = s[i];
            if (c != '*') {
                result.push_back(c);
            }
        }

        return result;
    }
};