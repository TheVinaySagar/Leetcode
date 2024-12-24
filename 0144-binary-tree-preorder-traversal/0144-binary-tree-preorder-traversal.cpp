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
    void func(TreeNode* root, vector<int> &elem)
    {
        
        if(root == nullptr)
        {
            return;
        }
        
        elem.push_back(root->val);
        func(root->left,elem);
        func(root->right,elem);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> elem;
        
        func(root,elem);
        
        return elem;
    }
};