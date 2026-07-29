class Solution {
public:
    int path(vector<vector<int>> &dp,vector<vector<int>> &grid,int r,int c){
        if(c==grid[0].size()-1&& r==grid.size()-1){
            return grid[r][c];
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int right=INT_MAX;
        int down=INT_MAX;
        if(r+1<grid.size()){
            down=path(dp,grid,r+1,c)+grid[r][c];
        }
        if(c+1<grid[0].size()){
            right=path(dp,grid,r,c+1)+grid[r][c];
        }
        dp[r][c]=min(down,right);
        return dp[r][c];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int pathsum=path(dp,grid,0,0);
        return pathsum;
    }
};