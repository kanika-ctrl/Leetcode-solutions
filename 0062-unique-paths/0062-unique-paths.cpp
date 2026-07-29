class Solution {
public:
    int path(vector<vector<int>> &dp,int row,int col){
       if(row==dp.size()-1||col==dp[0].size()-1){
        return 1;
       }
       if(dp[row][col]!=-1){
        return dp[row][col];
       }
       int down=path(dp,row+1,col);
       int right=path(dp,row,col+1);
       dp[row][col]=down+right;
       return dp[row][col];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int count=path(dp,0,0);
        return count;
     }
};