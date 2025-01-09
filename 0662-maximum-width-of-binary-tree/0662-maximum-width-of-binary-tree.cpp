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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode *,int>> q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty())
        {
            int n = q.size();
            int mmin = q.front().second;
            int maxi = 0;   
            int mini = 0;
            for(int i=0;i<n;i++)
            {   
                TreeNode *node = q.front().first;
                int parent_ind = q.front().second - mmin;
                q.pop();
                if(i==0) mini = parent_ind;
                if(i==n-1) maxi = parent_ind;
                if(node->left != nullptr) 
                    q.push({node->left, 1LL*parent_ind*2+1});
                
                if(node->right != nullptr)
                    q.push({node->right, 1LL*parent_ind*2+2});
            }
            ans = max(ans, maxi-mini+1);
        }
        return ans;
    }
};