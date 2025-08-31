class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        deque<TreeNode*>dq;
        dq.push_front(root);
        bool flag=false;
        while(!dq.empty()){
            int ls=dq.size();
            vector<int>ans;
            for(int i=0;i<ls;i++){
                if(flag==false){
                    TreeNode* node=dq.front();
                    dq.pop_front();
                    ans.push_back(node->val);
                    if(node->left){
                        dq.push_back(node->left);
                    }
                    if(node->right){
                        dq.push_back(node->right);
                    }
                }
                else if(flag==true){
                    TreeNode* node=dq.back();
                    dq.pop_back();
                    ans.push_back(node->val);
                    if(node->right){
                        dq.push_front(node->right);
                    }
                    if(node->left){
                        dq.push_front(node->left);
                    }
                }
            }
            res.push_back(ans);
             if(flag==true){
                    flag=false;
                }
                else{
                    flag=true;
                }
        }
        return res;
    }
};