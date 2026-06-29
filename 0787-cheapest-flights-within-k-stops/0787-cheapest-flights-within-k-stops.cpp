class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>> q;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &flight:flights){
            int u=flight[0];
            int v=flight[1];
            int w=flight[2];
            adj[u].push_back({v,w});
        }
        vector<int> dis(n,INT_MAX);
        dis[src]=0;
        q.push({src,0});
        int steps=0;
        while(!q.empty() && steps<=k){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int node=q.front().first;
                int w=q.front().second;
                q.pop();
               // if(dis[node]<w) continue;
                for(auto &edge:adj[node]){
                    int v=edge.first;
                    int d=edge.second;
                    if(d+w<dis[v]){
                        q.push({v,d+w});
                        dis[v]=d+w;
                    }
                }
            }
            steps++;
        }
        if(dis[dst]==INT_MAX) return -1;
        return dis[dst];
    }
};