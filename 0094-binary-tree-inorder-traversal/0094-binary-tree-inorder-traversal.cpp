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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> e;        
        stack<TreeNode *> stack;
        TreeNode *node = root;
        while(true)
        {
            if(node != nullptr)
            {
                stack.push(node);
                node = node->left;
            }
            else 
            {
                if(stack.empty() == true) break;
                node = stack.top();
                stack.pop();
                e.push_back(node->val);
                node = node->right;
            }
            
        }
        
        return e;
    }
};