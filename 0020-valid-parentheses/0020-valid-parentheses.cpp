class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> sta;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                sta.push(s[i]);
            } else {
                if (!sta.empty()) {
                    if ((sta.top() == '(' && s[i] == ')') ||
                        (sta.top() == '[' && s[i] == ']') ||
                        (sta.top() == '{' && s[i] == '}'))
                        sta.pop();

                    else
                        return false;
                }
                else
                {
                    return false;
                }
            }
        }

        return sta.empty();
    }
};