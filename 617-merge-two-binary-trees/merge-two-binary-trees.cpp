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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        // Case 1: If root1 is NULL, return root2
        if(root1==NULL)
        return root2;
        // Case 2: If root2 is NULL, return root1
        if(root2==NULL)
        return root1;
        // Case 3: Both nodes exist, add their values
        
        TreeNode* root3 = new TreeNode(root1->val+root2->val);

        // Recursively merge left subtrees
        root3->left=mergeTrees(root1->left,root2->left);


        // Recursively merge right subtrees
        root3->right=mergeTrees(root1->right,root2->right);


        // Return merged root
        return root3;
    }
};