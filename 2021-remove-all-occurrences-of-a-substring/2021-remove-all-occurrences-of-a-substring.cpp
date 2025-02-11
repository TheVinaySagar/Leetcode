class Solution {
public:
    string removeOccurrences(string s, string part) {
        // reverse(s.begin(), s.end());
        stack<char> sta;
        // for(auto &it:s)
        //     sta.push(it);

        // stack<int> sta1;
        // int j = 0;
        // while(!sta.empty())
        // {

        //     for(int k = 0;k<part.size();k++)
        //     {
        //         int curr = sta.top();

        //     }
        //     if( curr != part[j])
        //     {
        //         sta1.push(curr);
        //         sta.pop();
        //     }
        //     else
        //     {
        //         sta.pop();
        //     }
        // }

        // return s;

        int n = s.size();
        int m = part.size();

        for (int i = 0; i < n; i++) {
            sta.push(s[i]);

            if(sta.size() >= m) {
                string tempstr = "";
                stack<char> temp = sta;

                for (int k = 0; k < m; k++) {
                    tempstr = temp.top() + tempstr;
                    temp.pop();
                }

                if (tempstr == part) {
                    for (int k = 0; k < m; k++) {
                        sta.pop();
                    }
                }
            }
        }

        string str = "";
        while (!sta.empty()) {
            str = sta.top() + str;
            sta.pop();
        }

        return str;
    }
};