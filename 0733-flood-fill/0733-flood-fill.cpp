class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        if (image[sr][sc]==color){
            return image;
        }
        int m=image.size();
        int n=image[0].size();
        int c=image[sr][sc];
        vector<vector<int>> direction{{-1,0},{1,0},{0,-1},{0,1}};
        image[sr][sc]=color;
        while(!q.empty()){
            int N=q.size();
            for(int i=0;i<N;i++){
              pair<int,int> curr=q.front();
              q.pop();
              int y=curr.first;
              int j=curr.second;
              for(vector<int> &dir:direction){
                int new_i=y+dir[0];
                int new_j=j+dir[1];
        if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && image[new_i][new_j]==c){
                   image[new_i][new_j]=color;
                   q.push({new_i,new_j});
           }      
         }
            }
        }
        return image;
    }
};