class Solution {
public:
void nqueen(vector<vector<bool>> &grid,vector<vector<string>> &ans,int row){
    if(row==grid.size()){
        display(grid,ans);
        return ;
    }
    for(int col=0;col<grid.size();col++){
        if(issafe(grid,row,col)){
            grid[row][col]=1;
            nqueen(grid,ans,row+1);
            grid[row][col]=0;
        }
    }
    return;
}
bool issafe(vector<vector<bool>> &grid,int row,int col){
    for(int i=0;i<row;i++){
        if(grid[i][col]){
            return false;
        }
    }
    int leftmax=min(row,col);
    for(int i=1;i<=leftmax;i++){
        if(grid[row-i][col-i]){
            return false;
        }
    }
    int n=grid.size();
    int rightmax=min(row,n-col-1);
    for(int i=1;i<=rightmax;i++){
        if(grid[row-i][col+i]){
            return false;
        }
    }
    return true;
}
void display(vector<vector<bool>> &grid,vector<vector<string>> &ans){
    vector<string> temp;
    for(int i=0;i<grid.size();i++){
        string res="";
        for(int j=0;j<grid.size();j++){
            if(grid[i][j]==0){
              res+=".";
            }
            else{
                res+="Q";
            }
        }
       temp.push_back(res);
    }
    ans.push_back(temp);
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<bool>> grid(n,vector<bool>(n,0));
        nqueen(grid,ans,0);
        return ans;
    }
};