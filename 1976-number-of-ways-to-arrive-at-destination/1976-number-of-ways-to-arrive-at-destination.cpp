class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
       for (auto &road:roads){
            int u=road[0];
            int v=road[1];
            int w=road[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        } 
        vector<long long> ways(n,0);
        vector<long long> dis(n,LLONG_MAX);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        dis[0]=0;
        ways[0]=1;
        const int MOD = 1e9 + 7;
        while(!pq.empty()){
            int node=pq.top().second;
            long long weight=pq.top().first;
            pq.pop();
            if(dis[node]<weight) continue;
            for(auto &ngh:adj[node]){
                int u=ngh.first;
                int w=ngh.second;
                if(w+weight<dis[u]){
                    dis[u]=w+weight;
                    pq.push({w+weight,u});
                    ways[u]=ways[node];
                }
                else if(w+weight==dis[u]){
                    ways[u]=(ways[node]+ways[u])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};