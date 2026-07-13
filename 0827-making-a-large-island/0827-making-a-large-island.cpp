class Solution {
public:
int findparent(int u,vector<int> &parent){
    if(u==parent[u]) return u;
    return parent[u]=findparent(parent[u],parent);
}
void unionbysize(int u,int v,vector<int> &parent,vector<int> &size){
    int pu=findparent(u,parent);
    int pv=findparent(v,parent);
    if(size[pv]>size[pu]){
        size[pv]+=size[pu];
        parent[pu]=pv;
    }
    else{
        size[pu]+=size[pv];
        parent[pv]=pu;
    }
}
    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<int>> direction={{1,0},{-1,0},{0,1},{0,-1}};
        int n=grid.size();
        int m=n*n;
        vector<int> parent(m);
        vector<int> size(m,1);
        for(int i=0;i<m;i++){
            parent[i]=i;
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    res++;
                }
            }
        }
        if(res==m) return res;
        int ans=INT_MIN;
        int island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]==1){
                for(auto &dir:direction){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];
                    if(new_i>=0 && new_i<n && new_j>=0 && new_j<n && grid[new_i][new_j]==1){
                        int node=i*n+j;
                        int adjnode=new_i*n+new_j;
                        if(findparent(node,parent)!=findparent(adjnode,parent)){
                            unionbysize(node,adjnode,parent,size);
                        }
                    }
                }
               }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                set<int> st;
                if(grid[i][j]==0){
                    for(auto &dir:direction){
                        int new_i=i+dir[0];
                        int new_j=j+dir[1];
                        if(new_i>=0 && new_i<n && new_j>=0 && new_j<n && grid[new_i][new_j]==1){
                            int adjnode=new_i*n+new_j;
                            if(!st.count(findparent(adjnode,parent))){
                            int pu=findparent(adjnode,parent);
                            island+=size[pu];
                            st.insert(pu);
                        }
                        }
                    }
                    island++;
                ans=max(ans,island);
                island=0;
                }
            }
        }
        return ans;
    }
};