class Solution {
public:
    int paths(vector<vector<int>> &dp,vector<vector<int>> &obstacleGrid,int row,int col){
        if(row>=dp.size()||col>=dp[0].size()){
            return 0;
        }
        if(obstacleGrid[row][col]==1){
            return 0;
        }
        if(row==dp.size()-1 && col==dp[0].size()-1){
            return 1;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int down=paths(dp,obstacleGrid,row+1,col);
        int right=paths(dp,obstacleGrid,row,col+1);
        dp[row][col]=down+right;
        return dp[row][col];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int count=paths(dp,obstacleGrid,0,0);
        return count;
    }
};