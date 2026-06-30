/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    // Step 1 : Create Child -> Parent Mapping
    void markParents(TreeNode* root, map<TreeNode*, TreeNode*>& parent) {

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if(node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        map<TreeNode*, TreeNode*> parent;

        // Build Parent Mapping
        markParents(root, parent);

        // BFS from Target Node
        queue<TreeNode*> q;
        map<TreeNode*, bool> visited;

        q.push(target);
        visited[target] = true;

        int distance = 0;

        while(!q.empty()) {

            int size = q.size();

            // Stop when we reach distance K
            if(distance == k)
                break;

            distance++;

            while(size--) {

                TreeNode* node = q.front();
                q.pop();

                // Left Child
                if(node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }

                // Right Child
                if(node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }

                // Parent
                if(parent[node] && !visited[parent[node]]) {
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};