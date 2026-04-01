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
    void recoverTree(TreeNode* root) {
        TreeNode* curr=NULL;
        TreeNode* present=NULL;
        TreeNode* last=NULL;
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        while(root){
            if(!root->left){
                last=present;
                present=root;
                if(last!=NULL && present->val<last->val){
                    if(!first){
                        first=last;
                    }
                    second=present;
                }
                root=root->right;
            }
            else{
                curr=root->left;
                while(curr->right!=NULL && curr->right!=root){
                    curr=curr->right;
                }
                if(curr->right==NULL){
                    curr->right=root;
                    root=root->left;
                }
                else{
                    curr->right=NULL;
                    last=present;
                    present=root;
                   if(last!=NULL && last->val>present->val){
                    if(!first){
                        first=last;
                    }
                    second=present;
                   }
                root=root->right;
                }
            }
        }
        int data=first->val;
        first->val=second->val;
        second->val=data;
    }
};