class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
            }
        }
       vector<int> indegree(n,0);
       for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            indegree[adj[i][j]]++;
        }
       }
       queue<int> q;
       for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
       }
       vector<int> ans;
       while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int i=0;i<adj[node].size();i++){
            indegree[adj[node][i]]--;
            if(indegree[adj[node][i]]==0){
                q.push(adj[node][i]);
            }
        }
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};