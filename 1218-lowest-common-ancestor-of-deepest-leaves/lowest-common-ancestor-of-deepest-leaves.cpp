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
pair<int, TreeNode*> solve(TreeNode* root) {
    // Base case
    if (root == nullptr)
        return {0, nullptr};

    // Get height and LCA from both subtrees
    auto left = solve(root->left);
    auto right = solve(root->right);

    // Compare heights
    if (left.first == right.first)
        return {1 + left.first, root};

    if (left.first > right.first)
        return {1 + left.first, left.second};

    return {1 + right.first, right.second};
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).second;
    }
};