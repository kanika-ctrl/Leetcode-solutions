class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0||i==m-1||j==n-1){
                    if(grid[i][j]==1){
                     q.push({i,j});
                     grid[i][j]=2;
                    }
                }
            }
        }
        while(!q.empty()){
            int size=q.size();
            for(int k=0;k<size;k++){
                pair<int,int> curr=q.front();
                int i=curr.first;
                int j=curr.second;
                q.pop();
                for(auto &dir:directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    if(new_i>=0 && new_j>=0 && new_i<m && new_j<n && grid[new_i][new_j]==1){
                        grid[new_i][new_j]=2;
                        q.push({new_i,new_j});
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};