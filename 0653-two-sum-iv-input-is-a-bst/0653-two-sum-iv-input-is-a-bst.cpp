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
   bool func(TreeNode* root,int k,unordered_set<int> &set){
    if(!root) return false;

    int res=k-root->val;
    if(set.find(res)!=set.end()){
        return true;
    }
    set.insert(root->val);
    return func(root->left,k,set)||func(root->right,k,set);
   }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>set;
        return func(root,k,set);
    }
};