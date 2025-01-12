class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 == 1)
            return 0;
        stack<int> sta;
        stack<int> unlocked;

        for (int i = 0; i < n; i++) {
            if (locked[i] == '0')
                unlocked.push(i);
            else if (s[i] == '(')
                sta.push(i);
            else if (s[i] == ')') {
                if (!sta.empty())
                    sta.pop();
                else if (!unlocked.empty())
                    unlocked.pop();
                else
                    return false;
            }
        }
        while (!sta.empty() && !unlocked.empty() &&
                   sta.top() < unlocked.top()) {
                sta.pop();
                unlocked.pop();
            }

            if (sta.empty() && !unlocked.empty()) {
                return unlocked.size() % 2 == 0;
            }
            return sta.empty();
    }
};