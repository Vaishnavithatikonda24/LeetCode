#include <queue>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0; // Base case: Empty tree

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            depth++; // Increment depth at each level

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return depth;
    }
};
