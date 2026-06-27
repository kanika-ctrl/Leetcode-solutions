class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        map<pair<int,int>,int> mp;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    mp[{i,j}]=0;
                }
            }
        }
        int ans=1;
        if(grid[0][0]==1||grid[m-1][n-1]==1) return -1;
        mp[{0,0}]=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
            pair<int,int> curr=q.front();
            q.pop();
            int i=curr.first;
            int j=curr.second;
            if(i==m-1 && j==n-1) return ans;
            for(auto &dir:directions){
                int new_i=i+dir[0];
                int new_j=j+dir[1];
                if(new_i>=0 && new_j>=0 && new_i<m && new_j<n && grid[new_i][new_j]==0 && mp[{new_i,new_j}]==0){
                    q.push({new_i,new_j});
                    mp[{new_i,new_j}]=1;
                }
            }
        }
         ans++;
        }
        return -1;
    }
};