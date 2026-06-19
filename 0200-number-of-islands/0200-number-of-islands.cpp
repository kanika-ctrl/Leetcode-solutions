class Solution {
public:
    void bfs(vector<vector<char>>& grid,map <pair<int,int>,bool> &mp,pair<int,int> p,int &ans){
        int f=p.first;
        int s=p.second;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
        mp[{f,s}]=1;
        queue<pair<int,int>> q;
        q.push({f,s});
        while(!q.empty()){
         pair<int,int> curr=q.front();
         q.pop();
         int i=curr.first;
         int j=curr.second;
         for(auto &dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && grid[new_i][new_j]=='1'&&mp[{new_i,new_j}]==0){
                q.push({new_i,new_j});
                mp[{new_i,new_j}]=1;
            }
         }
        }
        ans++;
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        map<pair<int,int>,bool> mp;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    mp[{i,j}]=0;
                }
            }
        }
        int ans=0;
        for(auto m:mp){
            if(m.second==0){
                int i=m.first.first;
                int j=m.first.second;
                bfs(grid,mp,{i,j},ans);
            }
        }
        return ans;
    }
};