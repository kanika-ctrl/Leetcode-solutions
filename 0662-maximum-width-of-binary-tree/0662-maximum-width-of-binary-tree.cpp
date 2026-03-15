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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        int maxwid=0;
        while(!q.empty()){
          unsigned long long fidx=q.front().second;
          unsigned long long lidx=q.back().second;
            maxwid=max(maxwid,(int)(lidx-fidx+1));
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front().first;
                long long idx=q.front().second;
                q.pop();
                if(node->left){
                    q.push({node->left,idx*2+1});
                }
                if(node->right){
                    q.push({node->right,idx*2+2});
                }
            }
        }
        return maxwid;
    }
}; 