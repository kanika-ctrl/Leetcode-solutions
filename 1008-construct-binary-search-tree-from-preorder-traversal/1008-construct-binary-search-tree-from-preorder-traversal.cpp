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
   TreeNode* bst(vector<int> preorder,int &idx,int low,int high){
    if(idx>=preorder.size()||preorder[idx]<low||preorder[idx]>high){
        return NULL;
    }
    TreeNode* node=new TreeNode(preorder[idx++]);
    node->left=bst(preorder,idx,low,node->val);
    node->right=bst(preorder,idx,node->val,high);
    return node;
   }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return bst(preorder,idx,INT_MIN,INT_MAX);
    }
};