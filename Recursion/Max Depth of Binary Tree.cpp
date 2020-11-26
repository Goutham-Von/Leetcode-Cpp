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

int depthOfNode(TreeNode* node,int depth) {
    if (!node) {
        return depth;
    } else {
        depth += 1;
        int depth_l = depthOfNode(node->left, depth);
        int depth_r = depthOfNode(node->right, depth);
        return max(depth_r, max(depth_l, depth));
    }
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return depthOfNode(root, 0);
    }
};