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
int sum=0;
int helper(TreeNode* node,int dig){
    if(node==nullptr){
        return 0;
    }
  dig=dig*10+node->val;
  if(node->left==nullptr&&node->right==nullptr){
    sum+=dig;
  }
  int left=helper(node->left,dig);
  int right=helper(node->right,dig);
  return sum;
}
    int sumNumbers(TreeNode* root) {
       return helper(root,0);
    }
};