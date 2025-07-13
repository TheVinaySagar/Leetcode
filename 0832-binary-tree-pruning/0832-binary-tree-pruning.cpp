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
    TreeNode *solve(TreeNode *root)
    {
        if(!root)
         return nullptr;
        
        
        root->left = solve(root->left);
        root->right = solve(root->right);
        
        if(root->val == 0 && !root->left && !root->right )
        {
            // delete root;
            return nullptr;
        }
        
        return root;
    }

    TreeNode* pruneTree(TreeNode* root) {
        // TreeNode *node = root;
        return solve(root);
    }
};