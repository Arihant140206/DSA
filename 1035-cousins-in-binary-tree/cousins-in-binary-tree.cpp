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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
        return 0;

        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,NULL});

        while(!q.empty())
        {
            int size=q.size();
            TreeNode*parentX=NULL;
            TreeNode*parentY=NULL;

            for(int i=0;i<size;i++){
                auto [node, parent] = q.front();
                q.pop();
                if(node->val==x)
                parentX=parent;
                if(node->val==y)
                parentY=parent;

                if(node->left)
                q.push({node->left,node});
                if(node->right)
                q.push({node->right,node});

            }
            if(parentX||parentY){
            return parentX&&parentY&&parentX!=parentY;
            }



        }return false;
    }
};