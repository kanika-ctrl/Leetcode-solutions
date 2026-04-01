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
int maxsum=0;
class box{
    public:
    bool bst;
    int min,max,sum;
    box(int data){
        bst=1;
        min=data;
        max=data;
        sum=data;
    }
};
box* func(TreeNode* root){
    if(!root->left && !root->right){
        maxsum=max(maxsum,root->val);
        return new box(root->val);
    }
    else if(!root->left && root->right){
        box* head=func(root->right);
        if(head->bst && head->min>root->val){
            head->sum+=root->val;
            maxsum=max(maxsum,head->sum);
            head->min=root->val;
            return head;
        }
        else{
            head->bst=0;
            return head;
        }
    }
    else if(!root->right && root->left){
        box* head=func(root->left);
        if(head->bst && head->max<root->val){
            head->sum+=root->val;
            maxsum=max(maxsum,head->sum);
            head->max=root->val;
            return head;
        }
        else {
            head->bst=0;
            return head;
        }
    }
    else{
        box* lefthead=func(root->left);
        box* righthead=func(root->right);
        box* head=new box(root->val);
        if(lefthead->bst && righthead->bst && lefthead->max<root->val && righthead->min>root->val){
            head->sum+=lefthead->sum+righthead->sum;
            maxsum=max(maxsum,head->sum);
            head->min=lefthead->min;
            head->max=righthead->max;
            return head;
        }
        else{
            head->bst=0;
            return head;
        }
    }
}
    int maxSumBST(TreeNode* root) {
        func(root);
        return maxsum;
    }
};