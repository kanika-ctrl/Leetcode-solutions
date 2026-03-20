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
int prev=INT_MIN;
void helper(TreeNode* root,int &ans){
    if(!root){
        return;
    }
    helper(root->left,ans);
    if(prev!=INT_MIN){
    ans=min(ans,root->val-prev);
    }
    prev=root->val;
    helper(root->right,ans);
}
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        helper(root,ans);
        return ans;
    }
};