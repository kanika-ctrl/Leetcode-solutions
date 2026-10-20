class Solution {
public:
int diameter=0;
int height(TreeNode* root){
   if(root==nullptr){
    return 0;
   }
   int left_height=height(root->left);
   int right_height=height(root->right);
   int dia=left_height+right_height+1;
   diameter=max(diameter,dia);
   return max(left_height,right_height)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter-1;
    }
};