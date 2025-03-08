class Solution {
public:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;  // Both nodes are NULL, they are symmetric
        if (!t1 || !t2) return false; // One is NULL, the other is not

        return (t1->val == t2->val) &&
               isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true; // An empty tree is symmetric
        return isMirror(root->left, root->right);
    }
};
