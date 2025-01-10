class Solution {
public:
    vector<string> wordSubsets(vector<string>& word1, vector<string>& word2) {
        vector<int> mCf(26,0);
        vector<int> tCf(26);
        for(auto &it:word2)
        {
            fill(tCf.begin(), tCf.end(),0);
            for(auto l:it)
                tCf[l-'a']++;

            for(int i=0;i<26;i++)
                mCf[i] = max(mCf[i],tCf[i]);
        }

        
        vector<string> ans;
        for(auto &it:word1)
        {
            fill(tCf.begin(), tCf.end(),0);
            for(auto l:it)
                tCf[l-'a']++;

            bool isUni = true;
            for(int i=0;i<26;i++)
            {
                if(tCf[i] < mCf[i])
                {
                    isUni = false;
                    break;
                }
            }

            if(isUni) ans.push_back(it);
        }
        return ans;
    }
    
};