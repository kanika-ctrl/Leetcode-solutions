class Solution {
public:
int sudoko(vector<vector<char>>& board,int row,int col){
    if(row==board.size()){
        return 1;
    }
    if(col==board[0].size()){
       if(sudoko(board,row+1,0)){
        return 1;
       }
       return 0;
    }
    if(board[row][col]!='.'){
        if(sudoko(board,row,col+1)){
            return 1;
        }
        return 0;
    }
    for(int i=1;i<=9;i++){
        if(issafe(board,row,col,i)){
            board[row][col]=i+'0';
           if(sudoko(board,row,col+1)){
            return 1;
           }
            board[row][col]='.';
        }
    }
    return 0;
}
bool issafe(vector<vector<char>>& board,int row,int col,int num){
    for(int i=0;i<board.size();i++){
        if(board[row][i]==num+'0'){
            return false;
        }
    }
    for(int i=0;i<board.size();i++){
        if(board[i][col]==num+'0'){
            return false;
        }
    }
    int startrow=(row/3)*3;
    int startcol=(col/3)*3;
    int endrow=startrow+3;
    int endcol=startcol+3;
    for(int i=startrow;i<endrow;i++){
        for(int j=startcol;j<endcol;j++){
            if(board[i][j]==num+'0'){
                return false;
            }
        }
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        sudoko(board,0,0);
    }
};