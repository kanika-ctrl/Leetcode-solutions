class Solution {
public:
    void subpart(string s,vector<string> &ans,vector<vector<string>> &res){
        if(s.empty()){
            res.push_back(ans);
            return;
        }
        for(int i=0;i<s.size();i++){
            string p=s.substr(0,i+1);
            if(valid(p)){
                ans.push_back(p);
                string t=s.substr(i+1);
                subpart(t,ans,res);
                ans.pop_back();
            }
        }
    }
    bool valid(string s){
        int l=0;
        int r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        subpart(s,ans,res);
        return res;
    }
};