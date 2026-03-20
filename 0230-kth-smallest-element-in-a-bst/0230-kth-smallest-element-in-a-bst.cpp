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
int prev=0;
void helper(TreeNode* root,int &count,int k){
    if(!root) return;
    helper(root->left,count,k);
    if(count==k) return;
    prev=root->val;
    count++;
    helper(root->right,count,k);
}
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        helper(root,count,k);
        return prev;
    }
};