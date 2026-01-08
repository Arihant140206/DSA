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
public://iterative 
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
        if (root == NULL) return ans;
        stack<TreeNode*>s;
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode*temp=s.top();
            s.pop();
             ans.push_back(temp->val);
            if(temp->left)
            s.push(temp->left);
            if(temp->right)
            s.push(temp->right);
            
            
            

        }//general idea is to --Stack gives: Root → Right → Left(as right pop fisrt eve though left goes in first)then reverse it 

//Reversing gives: Left → Right → Root
        reverse(ans.begin(),ans.end());
        return ans;
    }
};