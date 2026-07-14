class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});
        visited[0][0]=1;
        while(!pq.empty()){
            auto curr=pq.top();
            int node=curr[0];
            int i=curr[1];
            int j=curr[2];
            pq.pop();
            if(i==n-1 && j==n-1) return node;
            for(auto &dir:dirs){
                int new_i=i+dir[0];
                int new_j=j+dir[1];
                if(new_i<n && new_i>=0 && new_j<n && new_j>=0 && visited[new_i][new_j]==0){
                    visited[new_i][new_j]=1;
                    if(node>grid[new_i][new_j]){
                        pq.push({node,new_i,new_j});
                    }
                    else{
                        pq.push({grid[new_i][new_j],new_i,new_j});
                    }
                }
            }
        }
        return -1;
    }
};