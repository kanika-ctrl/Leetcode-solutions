class Solution {
public:
void dfs(string word,string beginWord,unordered_map<string,vector<string>> &parent,vector<string> &path,vector<vector<string>> &ans){
    if(word==beginWord){
        vector<string> temp=path;
        reverse(temp.begin(),temp.end());
        ans.push_back(temp);
        return;
    }
    for(auto p:parent[word]){
        path.push_back(p);
        dfs(p,beginWord,parent,path,ans);
        path.pop_back();
    }
}
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> st;
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> parent;
        st.insert(wordList.begin(),wordList.end());
        if(!st.count(endWord)) return ans;
        st.erase(beginWord);
        q.push(beginWord);
        bool reached=false;
        while(!q.empty() && !reached){
            int sz=q.size();
            unordered_set<string> usedthislevel;
            while(sz--){
             string curr=q.front();
             q.pop();
             if(curr==endWord) reached=true;
             for(int i=0;i<curr.size();i++){
                string temp=curr;
                for(int j=97;j<=122;j++){
                    if(temp[i]==j) continue;
                    temp[i]=j;
                    if(st.count(temp)){
                        if(usedthislevel.find(temp)==usedthislevel.end()){
                            usedthislevel.insert(temp);
                            q.push(temp);
                        }
                      parent[temp].push_back(curr);

                    }
                }
             }
            }
            for(auto p:usedthislevel){
                st.erase(p);
            }
        }
        if(!reached) return ans;
        vector<string> path;
        path.push_back(endWord);
        dfs(endWord,beginWord,parent,path,ans);
        return ans;
    }
};