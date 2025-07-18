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
    bool isSysUtils(TreeNode *left, TreeNode *right)
    {
        if(!left || !right)
            return left==right;
        
        if(left->val != right->val) return false;
        return isSysUtils(left->left, right->right) && isSysUtils(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        // return root==nullptr || isSysUtils(root->left, root->right);
        if(!root)
            return true;

        queue<TreeNode *> que;
        que.push(root->left);
        que.push(root->right);

        while(!que.empty())
        {
            TreeNode *ele1 = que.front(); que.pop();
            TreeNode *ele2 = que.front(); que.pop();

            if(!ele1 && !ele2) continue;
            if(!ele1 || !ele2 || ele1->val != ele2->val) return false;

            que.push(ele1->left);
            que.push(ele2->right);
            que.push(ele1->right);
            que.push(ele2->left); 
        }

        return true;
    }
};