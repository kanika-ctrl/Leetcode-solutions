class Solution {
public:
   bool dfs(vector<vector<int>>& graph,vector<int> &colorlist,int currcolor,int curr){
    colorlist[curr]=currcolor;
    for(int i=0;i<graph[curr].size();i++){
        if(colorlist[curr]==colorlist[graph[curr][i]]){
            return false;
        }
        if(colorlist[graph[curr][i]]==-1){
             int vcolor=1-currcolor;
             if(!dfs(graph,colorlist,vcolor,graph[curr][i])){
                return false;
             }
        }
    }
    return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        int N=graph.size();
        vector<int>colorlist(N,-1);
        for(int i=0;i<graph.size();i++){
            if(colorlist[i]==-1){
                if(!dfs(graph,colorlist,1,i)){
                    return false;
                }
            }
        }
        return true;
    }
};