class Solution {
public:

    int isVowel(char ch)
    {
        // Make the list of vowels
        string str = "aeiou";
        return (str.find(ch) != string::npos);
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> counts(n,0);
        for(int i=0;i<n;i++)
        {
            if(isVowel(words[i][0]) && isVowel(words[i][words[i].size()-1]))
                counts[i] = 1;
        }
        vector<int> preffix(n+1,0);
        for(int i=1;i<=n;i++)
            preffix[i] = preffix[i-1] + counts[i-1];
        vector<int> ans;
        for (auto& query : queries) {
            int left = query[0], right = query[1];
            int cnt = preffix[right + 1] - preffix[left];
            ans.push_back(cnt);
        }

        return ans;    
    }
};