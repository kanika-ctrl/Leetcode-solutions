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
long long prev= LLONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root){
            return 1;
        }
        bool left=isValidBST(root->left);
        if(left==0){
            return 0;
        }
        if(prev>=root->val){
            return 0;
        }
        prev=root->val;
        return isValidBST(root->right);
    }
};