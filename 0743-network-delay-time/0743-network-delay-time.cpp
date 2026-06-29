class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &time:times){
            int u=time[0];
            int v=time[1];
            int w=time[2];
            adj[u].push_back({v,w});
        }
        vector<int> dis(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        dis[k]=0;
        
        while(!pq.empty()){
            int d=pq.top().first;
            int v=pq.top().second;
            pq.pop();
            if(dis[v]<d) continue;
            for(auto &edge:adj[v]){
                int node=edge.first;
                int w=edge.second;
                if(w+d<dis[node]){
                    pq.push({w+d,node});
                    dis[node]=w+d;
                }
            }
        }
        int ans=dis[1];
        if(dis[1]==INT_MAX) return -1;
        for(int i=2;i<=n;i++){
            if(dis[i]==INT_MAX) return -1;
            else{
             ans=max(ans,dis[i]);
            }
        }
         return ans;
    }
};