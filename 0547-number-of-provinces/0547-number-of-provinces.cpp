class Solution {
public:
  void traversal(int node,vector<vector<int>> &adj,vector<bool> &visited){
    visited[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                visited[adj[node][i]]=1;
                q.push(adj[node][i]);
            }
        }
    }
  }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<vector<int>> adj(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
              if(isConnected[i][j]){
                adj[i].push_back(j);
            }
            }
        }
        int count=0;
        vector<bool> visited(v,0);
        for(int i=0;i<v;i++){
            if(!visited[i]){
                traversal(i,adj,visited);
                count++;
            }
        }
        return count;
    }
};