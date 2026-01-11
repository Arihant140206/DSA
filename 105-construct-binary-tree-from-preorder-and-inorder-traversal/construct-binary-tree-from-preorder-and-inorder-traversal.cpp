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
 class Solution{
public://book se comapred halke halke changes hai code me par code logic is same 
 
int find(vector<int>&in , int target,int start,int end){
    for(int i=start;i<=end;i++)
    {
        if(in[i]==target)
        return i;
    }
return -1;
}

TreeNode*Tree(vector<int>&in,vector<int>&pre,int instart,int inend,int index)
{
    if(instart>inend)
    return NULL;
    TreeNode*root=new TreeNode(pre[index]);
    int pos=find(in,pre[index],instart,inend);
    root->left=Tree(in,pre,instart,pos-1,index+1);
    root->right=Tree(in,pre,pos+1,inend,index+(pos-instart)+1);
    return root;
}//letcode me ye buidtree diya tha toh end me call karna padta hai apne actual tree wale fn ko bvuildtre ke andar also har jaqgah int* ke bajay vector<int>& use karna hai 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return Tree(inorder, preorder, 0, inorder.size() - 1, 0);
    }
 };