/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string s;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                s.append("#,");
            } else {
                s.append(to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout << s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = nullptr;
        try {
            root = new TreeNode(stoi(str));
        } catch (const std::invalid_argument& e) {
            cout << "Invalid argument: " << e.what() << endl;
            return nullptr;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (getline(s, str, ',')) {
                if (str == "#") {
                    node->left = nullptr;
                } else {
                    try {
                        TreeNode* leftNode = new TreeNode(stoi(str));
                        node->left = leftNode;
                        q.push(leftNode);
                    } catch (const std::invalid_argument& e) {
                        cout << "Invalid argument for left node: " << e.what() << endl;
                    }
                }
            }

            if (getline(s, str, ',')) {
                if (str == "#") {
                    node->right = nullptr;
                } else {
                    try {
                        TreeNode* rightNode = new TreeNode(stoi(str));
                        node->right = rightNode;
                        q.push(rightNode);
                    } catch (const std::invalid_argument& e) {
                        cout << "Invalid argument for right node: " << e.what() << endl;
                    }
                }
            }
        }

        return root;
    }
};
// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         queue<TreeNode *> q;
//         q.push(root);
//         string s; 
//         while(!q.empty())
//         {
//             TreeNode *node = q.front();
//             q.pop();
//             if(node == nullptr) s.append("#,");
//             else s.append(to_string(node->val)+',');
//             if(node != nullptr)
//             {
//                 q.push(node -> left);
//                 q.push(node -> right);
//             }
//         }
//         cout<<s;
//         return s;

//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         if(data.size() == 0) return nullptr;
//         stringstream s(data);
//         string str;
//         getline(s,str,',');
//         TreeNode *root = new TreeNode(stoi(str));
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty())
//         {
//             TreeNode *node = q.front();
//             q.pop();

//             getline(s, str, ',');
//             if(str == "#")
//                 node->left = nullptr;
//             else
//             {
//                 TreeNode* leftNode = new TreeNode(stoi(str));
//                 node->left = leftNode;
//                 q.push(leftNode);
//             }

//             getline(s, str, ',');
//             if(str == "#")
//                 node->right = nullptr;
//             else 
//             {
//                 TreeNode *rightNode = new TreeNode(stoi(str));
//                 node->right = rightNode;
//                 q.push(rightNode);
//             }
//         }

//         return root;
//     }
// };

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));