class Solution {
public:
    vector<int> dir={1,0,-1};
    int maxcherry(vector<vector<int>> &grid,vector<vector<vector<int>>> &dp,int col1,int col2,int row){
        if(max(col1,col2)>=grid[0].size()||min(col1,col2)<0){
            return -1e9;
        }
        if(row==grid.size()-1){
            if(col1==col2){
                return grid[row][col1];
            }
            else{
                return grid[row][col1]+grid[row][col2];
            }
        }
        if(dp[row][col1][col2]!=-1){
            return dp[row][col1][col2];
        }
        int cherries;
        int ans=INT_MIN;
        for(int i=0;i<dir.size();i++){
            for(int j=0;j<dir.size();j++){
                int c1=dir[i]+col1;
                int c2=dir[j]+col2;
                if(col1==col2)
                {
                    cherries=grid[row][col1];
                }
                else{
                     cherries=grid[row][col1]+grid[row][col2];
                }
                cherries+=maxcherry(grid,dp,c1,c2,row+1);
                ans=max(ans,cherries);
            }
        }
        
        return dp[row][col1][col2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        int cherries=maxcherry(grid,dp,0,m-1,0);
        return cherries;
    }
};