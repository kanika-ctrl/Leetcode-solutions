class Solution {
public:
vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
bool search(vector<vector<char>>& board,int row,int col,string &word,int idx){
    if(idx==word.size()){
        return true;
    }
    if(row<0 || col<0 || row>board.size()-1 || col> board[0].size()-1 || board[row][col]=='#'){
        return false;
    }
    if(board[row][col]!=word[idx]){
          return false;
    }
    int temp=board[row][col];
    board[row][col]='#';
    for(auto &dir:dirs){
        int new_i=row+dir[0];
        int new_j=col+dir[1];
        if(search(board,new_i,new_j,word,idx+1)){
            return true;
        }
    }
    board[row][col]=temp;
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && search(board,i,j,word,0)){
                   return true;
                }
            }
        }
        return false;
    }
};