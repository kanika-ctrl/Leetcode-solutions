class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //number of rows
        int m=mat.size();
        //number of cols
        int n=mat[0].size();
        vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>>q;
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int>curr=q.front();
            int i=curr.first;
            int j=curr.second;
            q.pop();
            for(vector<int> &dir:directions){
              int new_i=i+dir[0];
              int new_j=j+dir[1];
              if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && mat[new_i][new_j]==1){
                ans[new_i][new_j]=abs(i-new_i)+abs(j-new_j)+ans[i][j];
                q.push({new_i,new_j});
                mat[new_i][new_j]=0;
              }
            }
        }
        return ans;
    }
};