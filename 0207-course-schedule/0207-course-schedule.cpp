class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &edge: prerequisites){
            int u=edge[1];
            int v=edge[0];
            adj[u].push_back(v);
        }
        vector<int> indegree(numCourses,0);
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int processed=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            processed++;
            for(int i=0;i<adj[node].size();i++){
              indegree[adj[node][i]]--;
              if(indegree[adj[node][i]]==0){
                q.push(adj[node][i]);
              }
            }
        }
        if(processed==numCourses){
            return true;
        }
        return false;
    }
};