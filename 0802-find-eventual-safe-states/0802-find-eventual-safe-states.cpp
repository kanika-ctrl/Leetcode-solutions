class Solution {
public:
bool dfs(vector<vector<int>>& graph,vector<bool> &visited,vector<bool> &inrec,int node){
    visited[node]=1;
    inrec[node]=1;
    for(int i=0;i<graph[node].size();i++){
        if(!visited[graph[node][i]] && dfs(graph,visited,inrec,graph[node][i])){
      return true;
        }
        else if(inrec[graph[node][i]]){
            return true;
        }
    }
    inrec[node]=0;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> visited(n,0);
        vector<bool> inrec(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(graph,visited,inrec,i);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(inrec[i]!=1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};