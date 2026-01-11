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
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int inStart, int inEnd) {

        if (inStart > inEnd)
            return NULL;

        // Create root from preorder
        TreeNode* root = new TreeNode(preorder[preIndex++]);

        // If leaf node
        if (inStart == inEnd)
            return root;

        // Find root in inorder (linear search)
        int mid;
        for (mid = inStart; mid <= inEnd; mid++) {
            if (inorder[mid] == root->val)
                break;
        }

        // Build left and right subtrees
        root->left = build(preorder, inorder, inStart, mid - 1);
        root->right = build(preorder, inorder, mid + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};
