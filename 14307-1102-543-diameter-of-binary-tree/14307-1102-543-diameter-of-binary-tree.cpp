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


int maxi = -1e9;

class Solution {
public:
    int check(TreeNode *root, int &maxi)
    {
        if(root==nullptr)
            return 0;
        
        int l(0),r(0);
        
        l = check(root->left, maxi);
        r = check(root->right, maxi);
        
        maxi = max(maxi, (l+r));
        
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        check(root,maxi);
        return maxi;
    }
};