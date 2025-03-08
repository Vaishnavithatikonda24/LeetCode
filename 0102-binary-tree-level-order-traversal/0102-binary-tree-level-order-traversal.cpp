#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result; // If the tree is empty, return empty list

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size(); // Number of nodes at the current level
            vector<int> level;

            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
        }

        return result;
    }
};
