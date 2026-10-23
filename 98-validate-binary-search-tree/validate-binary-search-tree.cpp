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

    bool fun(TreeNode* root, long long low, long long high)
    {
        if(root == NULL)
            return true;

        if(root->val <= low || root->val >= high)
            return false;

        return fun(root->left, low, root->val) &&
               fun(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        // llong min and max are used for a larger range of values of root ,
        //later low--llong_min , so left range in recursion ,and high is llong_max which is right range 
        return fun(root, LLONG_MIN, LLONG_MAX);

    }
};