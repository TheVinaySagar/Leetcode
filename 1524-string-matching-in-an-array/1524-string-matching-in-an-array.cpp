class Solution {
public:
    bool checkSubStr(string& s, string& t) {
        size_t pos = t.find(s);

        return pos != string::npos;
    }
    int comp(string& s, string& t) { return s.size() < t.size(); }
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](const std::string &s, const std::string &t) {
        return s.size() < t.size();
    });
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                if (i != j) {
                    if (checkSubStr(words[i], words[j]))
                    {
                        ans.push_back(words[i]);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};