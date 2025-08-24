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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()||postorder.empty()){
            return nullptr;
        }
        int n=postorder.size()-1;
        int rootval=postorder[n];
        int idx=0;
        TreeNode* root=new TreeNode(rootval);
        for(int i=0;i<inorder.size();i++){
            if(rootval==inorder[i]){
                idx=i;
                break;
            }
        }
        vector<int>leftin(inorder.begin(),inorder.begin()+idx);
        vector<int>rightin(inorder.begin()+idx+1,inorder.end());
        vector<int>postleft(postorder.begin(),postorder.begin()+leftin.size());
        vector<int>postright(postorder.begin()+leftin.size(),postorder.end()-1);
        root->left=buildTree(leftin,postleft);
        root->right=buildTree(rightin,postright);
        return root;
    }
};