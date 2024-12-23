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
    int minSwapsToSort(std::vector<int>& levelValues) {
        int n = levelValues.size();
        std::vector<std::pair<int, int>> valueIndexPairs(n);

        // Store the value-index pairs
        for (int i = 0; i < n; ++i) {
            valueIndexPairs[i] = {levelValues[i], i};
        }

        // Sort the pairs based on the values
        std::sort(valueIndexPairs.begin(), valueIndexPairs.end());

        // Visited array to track visited indices
        std::vector<bool> visited(n, false);
        int swapCount = 0;

        // Iterate over the array to count cycles
        for (int i = 0; i < n; ++i) {
            // If already visited or in the correct position, skip
            if (visited[i] || valueIndexPairs[i].second == i) {
                continue;
            }

            // Count the size of the cycle
            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = valueIndexPairs[j].second;
                cycleSize++;
            }

            // Add the number of swaps for this cycle
            if (cycleSize > 1) {
                swapCount += (cycleSize - 1);
            }
        }

        return swapCount;
    }
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        std::queue<TreeNode*> q;
        q.push(root);

        int totalSwaps = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            std::vector<int> levelValues;

            // Collect all node values at the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                levelValues.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Calculate the minimum swaps needed to sort the current level
            totalSwaps += minSwapsToSort(levelValues);
        }

        return totalSwaps;
    }
};