class Codec {
public:
void helper(TreeNode* root,string &res){
     if(root==nullptr){
        res+="N,";
        return;
     }
     res+=(to_string(root->val))+",";
     helper(root->left,res);
     helper(root->right,res);
}
TreeNode* helper2(vector<string> &res){
    if(res.empty()){
        return  nullptr;
    }
    string val=res.back();
    res.pop_back();
    if(val=="N"){
        return nullptr;
    }
    TreeNode* root=new TreeNode(stoi(val));
    root->left=helper2(res);
    root->right=helper2(res);
    return root;
}
vector<string>split(const string &s,char delim){
    vector<string> tokens;
    string token;
    stringstream ss(s);
    while(getline(ss,token,delim)){
        tokens.push_back(token);
    }
    return tokens;
}
    string serialize(TreeNode* root) {
        string res;
        helper(root,res);
        return res;
    }

    TreeNode* deserialize(string data) {
        vector<string> res=split(data,',');
        reverse(res.begin(),res.end());
        return helper2(res);
    }
};