#include <vector>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result; // Return empty list if tree is empty

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true; // Flag to track traversal direction

        while (!q.empty()) {
            int level_size = q.size();
            deque<int> level; // Use deque for efficient insertion

            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (leftToRight)
                    level.push_back(node->val); // Append normally
                else
                    level.push_front(node->val); // Append at the front (reverse order)

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(vector<int>(level.begin(), level.end()));
            leftToRight = !leftToRight; // Toggle direction
        }

        return result;
    }
};
