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
int height(TreeNode* root,bool flag){
    if(root==nullptr){
        return 0;
    }
    if(flag==true){
       return 1+ height(root->left,true);
    }
    else{
        return 1+height(root->right,false);
    }
}
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int left=height(root,true);
        int right=height(root,false);
        if(left==right){
            return pow(2,left)-1;
        }
        return 1+(countNodes(root->left)+countNodes(root->right));
    }
};