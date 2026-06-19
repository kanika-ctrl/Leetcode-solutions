class Solution {
public:
bool iscycle(vector<vector<int>>& adj,vector<bool> &visited,vector<bool> &inrec,int u){
    visited[u]=1;
    inrec[u]=1;
    for(int i=0;i<adj[u].size();i++){
        if(!visited[adj[u][i]]&&iscycle(adj,visited,inrec,adj[u][i])){
            return true;
        }
        else if (inrec[adj[u][i]]){
           return true;
        } 
    }
    inrec[u]=0;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int courses=prerequisites[i][0];
            int prereq=prerequisites[i][1];
            adj[prereq].push_back(courses);
        }
        vector<bool> visited(numCourses,0);
        vector<bool> inrec(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]&&iscycle(adj,visited,inrec,i)){
                return false;
            }
        }
        return true;
    }
};