/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void printsubtree(TreeNode* root,int k,vector<int> &ans){
    if(!root||k<0){
        return;
    }
    if(k==0){
        ans.push_back(root->val);
    }
    printsubtree(root->left,k-1,ans);
    printsubtree(root->right,k-1,ans);
}
int printnode(TreeNode* root,TreeNode*target,int k,vector<int> &ans){
    if(!root){
        return -1;
    }
    if(root==target){
        printsubtree(root,k,ans);
        return 0;
    }
    int dl=printnode(root->left,target,k,ans);
    if(dl!=-1){
        if(dl+1==k){
            ans.push_back(root->val);
        }
        else{
            printsubtree(root->right,k-dl-2,ans);
        }
        return dl+1;
    }
    int dr=printnode(root->right,target,k,ans);
    if(dr!=-1){
        if(dr+1==k){
            ans.push_back(root->val);
        }
        else{
            printsubtree(root->left,k-dr-2,ans);
        }
        return dr+1;
    }
    return -1;
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        printnode(root,target,k,ans);
        return ans;

    }
};