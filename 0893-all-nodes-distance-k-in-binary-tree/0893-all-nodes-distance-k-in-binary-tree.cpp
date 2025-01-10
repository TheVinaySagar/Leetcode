/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void parentTrack(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &par)
    {
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *p = q.front();
            q.pop();

            if(p->left != nullptr) 
            {
                par[p->left] = p;
                q.push(p->left); 
            }

            if(p->right != nullptr)
            {
                par[p->right] = p;
                q.push(p->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> par;
        parentTrack(root, par);

        queue<TreeNode *> q;
        unordered_map<TreeNode *, bool> visited; 
        q.push(target);
        visited[target] = true;
        int cur_level = 0;
        while(!q.empty())
        {
            int n = q.size();
            if(cur_level == k) break;
            cur_level++;
            for(int i=0;i<n;i++)
            {
                TreeNode *current = q.front();
                q.pop();

                if(current->left && !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right] = true;
                }

                if(par[current] && !visited[par[current]])
                {
                    q.push(par[current]);
                    visited[par[current]] = true;
                }
            }
        }

        vector<int> ans;
        cout<<q.size()<<endl;
        while(!q.empty())
        {
            int v = q.front()->val;
            q.pop();
            ans.push_back(v);
            
        }
        return ans;
    }
};