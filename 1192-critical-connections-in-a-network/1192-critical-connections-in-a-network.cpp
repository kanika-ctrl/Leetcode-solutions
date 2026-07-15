class Solution {
public:
void dfs(int node,int parent,int count,vector<int> &low,vector<int> &disc,vector<vector<int>> &adj,vector<bool> &visited,vector<vector<int>> &bridge ){
    low[node]=disc[node]=count;
    visited[node]=1;
    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i]==parent) continue;
        else if(visited[adj[node][i]]){
            low[node]=min(low[node],low[adj[node][i]]);
        }
        else{
            count++;
           dfs(adj[node][i],node,count,low,disc,adj,visited,bridge);
           if(disc[node]<low[adj[node][i]]){
            bridge.push_back({node,adj[node][i]});
           }
           low[node]=min(low[node],low[adj[node][i]]);
        }

    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &edge:connections){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        vector<int> disc(n);
        vector<int> low(n);
        vector<bool> visited(n,0);
        vector<vector<int>> bridge;
        dfs(0,-1,0,low,disc,adj,visited,bridge);
         return bridge;
    }
};