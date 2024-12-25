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
    vector<int> largestValues(TreeNode* root) {
        
        queue<TreeNode *> q;
        q.push(root);
        vector<int> temp;
        if(root==nullptr) return temp;
        while(!q.empty())
        {
            int n = q.size();
            int maxi = INT_MIN;
            for(int i=0;i<n;i++)
            {
                TreeNode *ele = q.front();
                q.pop();
                maxi = max(maxi, ele->val);
                
                if(ele->left != nullptr) q.push(ele->left);
                if(ele->right != nullptr) q.push(ele->right);
            }
            temp.push_back(maxi);
        }
        return temp;
    }
};