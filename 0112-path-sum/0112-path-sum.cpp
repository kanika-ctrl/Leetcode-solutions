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
   bool helper(TreeNode* root,int sum,int target){
    if(!root->left&&!root->right){
        if(sum==target){
            return true;
        }
        return false;
    }
    bool leftval,rightval=false;
    if(root->left){
         leftval=helper(root->left,sum+root->left->val,target);
    }
    if(root->right){
         rightval=helper(root->right,sum+root->right->val,target);
    }
    return leftval||rightval;
   }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        return helper(root,root->val,targetSum);
    }
};