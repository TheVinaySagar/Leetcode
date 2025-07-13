/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> que;
        que.push(root);
        
        vector<double> ans;
        while(!que.empty())
        {
            int siz = que.size();
            
            double add = 0;
            for(int i=0;i<siz;i++)
            {
                TreeNode *ele = que.front();
                que.pop();
                
                add += ele->val;
                
                if(ele->left) que.push(ele->left);
                if(ele->right) que.push(ele->right);
            }
            
            ans.push_back(add/(double)siz);
        }
        
        return ans;
    }
};