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

    int count(TreeNode *root)
    {
        if(!root) return 0;
        int l(0), r(0);
        if(root->left) l = count(root->left) + 1;
        if(root->right) r = count(root->right) + 1;

        return l + r;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return count(root) + 1;
    }
};