class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
       priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;
        pq.push({0,{0,0}});
        dis[0][0]=0;
        while(!pq.empty()){
            int diff=pq.top().first;
            pair<int,int> node=pq.top().second;
            int i=node.first;
            int j=node.second;
            pq.pop();
            if(i==m-1 && j==n-1) return diff;
            if(diff>dis[i][j]){
                continue;
            }
            for(auto &dir:directions){
                int new_i=i+dir[0];
                int new_j=j+dir[1];
                if(new_i<m && new_j<n && new_i>=0 && new_j>=0){
                    int new_effort=abs(heights[i][j]-heights[new_i][new_j]);
                    int maxeffort=max(new_effort,diff);
                    if(dis[new_i][new_j]>maxeffort){
                        dis[new_i][new_j]=maxeffort;
                        pq.push({maxeffort,{new_i,new_j}});
                    }
                }
            }
        }
        return dis[m-1][n-1];
    }
};