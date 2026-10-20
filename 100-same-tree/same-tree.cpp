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
    bool isSameTree(TreeNode* p, TreeNode* q) {
    // Case 1: Both are nullptr
    // YOUR CONDITION
    if(p==NULL&&q==NULL)
    return true;

    // Case 2: Only one is nullptr
    // YOUR CONDITION
    if(p==NULL||q==NULL)
    return false;

    // Case 3: Values differ
    // YOUR CONDITION
    if(p->val!=q->val)
    return false;

    // Case 4: Compare both subtrees
    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
           
}
};