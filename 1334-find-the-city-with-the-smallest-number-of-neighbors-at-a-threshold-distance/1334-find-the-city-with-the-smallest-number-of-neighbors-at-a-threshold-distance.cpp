class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int>(n,INT_MAX));
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            mat[u][v]=w;
            mat[v][u]=w;
        }
        for(int i=0;i<n;i++){
            mat[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][k]==INT_MAX||mat[k][j]==INT_MAX)  continue;
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        pair<int,int> ans;
        ans.second=INT_MAX;
        int count=0;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]<=distanceThreshold && i!=j){
                     count++;
                }
            }
            if(ans.second>count){
                ans.second=count;
                ans.first=i;
            }
            
            count=0;
        }
        return ans.first;
    }
};