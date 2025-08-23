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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()|| inorder.empty()){
            return nullptr;
        }
        int rootval=preorder[0];
        TreeNode* root=new TreeNode(rootval);
        int idx=0;
        for(int i=0;i<inorder.size();i++){
            if(rootval==inorder[i]){
                idx=i;
                break;
            }
        } 
        vector<int>leftpre(preorder.begin()+1,preorder.begin()+idx+1);
        vector<int>leftin(inorder.begin(),inorder.begin()+1+idx);
        vector<int>rightpre(preorder.begin()+idx+1,preorder.end());
        vector<int>rightin(inorder.begin()+1+idx,inorder.end());
        
        root->left=buildTree(leftpre,leftin);
        root->right=buildTree(rightpre,rightin);
        return root;
    }
};