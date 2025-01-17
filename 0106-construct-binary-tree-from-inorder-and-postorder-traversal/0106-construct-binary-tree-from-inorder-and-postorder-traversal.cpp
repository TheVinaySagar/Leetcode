/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (auto i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        TreeNode *root = build(inorder, 0, inorder.size()-1,
                                postorder, 0, postorder.size()-1, mp);
        return root;
    }

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd, unordered_map<int,int> &mp) {
        
        if(inStart>inEnd || postStart>postEnd)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[postEnd]);
        int inroot = mp[root->val];
        int numsLeft = inroot-inStart;

        root->left = build(inorder,inStart,inroot-1,
                            postorder,postStart,postStart+numsLeft-1,mp);
        root->right = build(inorder,inroot+1,inEnd,
                            postorder, postStart+numsLeft,postEnd-1, mp);
        return root;
    }
};