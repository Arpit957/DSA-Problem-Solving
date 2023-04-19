class Solution {
public:
  int res = 0;

    void solve(TreeNode* node, bool goLeft, int currPathLen) {
        if (!node) return;
        res = max(res, currPathLen);
        if (goLeft) {
            solve(node->left, false, currPathLen + 1);
            solve(node->right, true, 1);
        } else {
            solve(node->right, true, currPathLen + 1);
            solve(node->left, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        solve(root, true, 0);
        solve(root, false, 0);
        return res;
    }
};
