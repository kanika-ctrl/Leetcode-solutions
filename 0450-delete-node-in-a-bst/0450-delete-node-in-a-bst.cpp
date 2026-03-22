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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val>key){
            root->left=deleteNode(root->left,key);
            return root;
        }
       else if(root->val<key){
            root->right=deleteNode(root->right,key);
            return root;
        }
        else{
            if(!root->left&&!root->right){
                return NULL;
            }
            else if(!root->right){
                 TreeNode* node=root->left;
                 delete(root);
                 return node;
            }
            else if(!root->left){
                TreeNode* node=root->right;
                delete(root);
                return node;
            }
            else if(root->left&&root->right){
                TreeNode* parent=root;
                TreeNode* child=root->left;
                while(child->right){
                    parent=child;
                    child=child->right;
                }
                if(!child->left&&parent==root){
                    child->right=root->right;
                    delete(root);
                    return child;
                }
                else if(!child->left&&parent!=root){
                    child->left=root->left;
                    child->right=root->right;
                    delete(root);
                    parent->right=NULL;
                    return child;
                }
               else if(child->left&&parent==root){
                    child->right=root->right;
                    delete(root);
                    return child;
                }
               else if(child->left&&parent!=root){
                parent->right=NULL;
                   parent->right=child->left;
                   child->left=root->right;
                   delete(root);
                   return child;
                }
            }
        }
        return root;
    }
};