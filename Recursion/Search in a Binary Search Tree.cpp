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
    TreeNode* node;
    void bstSearch(TreeNode* stem, int val){
                if (!stem) return;
                if (stem->val == val){
                    node = stem;
                    return;
                }
                bstSearch(stem->left, val);
                bstSearch(stem->right, val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        bstSearch(root, val);
        return node;
    }
};