class Solution {  
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0||i==m-1||j==n-1){
                    if(board[i][j]=='O'){
                        board[i][j]='#';
                        q.push({i,j});
                    }
                }
            }
        }
        while(!q.empty()){
            int size=q.size();
            for(int k=0;k<size;k++){
                pair<int,int> curr=q.front();
                q.pop();
                int i=curr.first;
                int j=curr.second;
                for(auto &dir:directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    if(new_i>0&&new_i<m&&new_j>0&&new_j<n&&board[new_i][new_j]=='O'){
                        board[new_i][new_j]='#';
                        q.push({new_i,new_j});
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};