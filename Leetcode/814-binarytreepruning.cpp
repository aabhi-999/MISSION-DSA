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
    bool solve(TreeNode* &root) {
        if (!root) return true;
        bool left = solve(root->left);
        bool right = solve(root->right);
        if (left) {
            root->left = NULL;
        }
        if (right) {
            root->right = NULL;
        }
        return (root->val == 0 && !root->left && !root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if (solve(root)) {
            return NULL;
        }
        return root;
    }
};
