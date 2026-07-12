class Solution {
public:
int findparent(int u,vector<int> &parent){
    if(u==parent[u]) return u;
    return parent[u]=findparent(parent[u],parent);
}
void unionbysize(int u,int v,vector<int> &parent, vector<int> &size){
    int pu=findparent(u,parent);
    int pv=findparent(v,parent);
    if(pu==pv) return ;
    if(size[pv]>size[pu]){
        size[pv]+=size[pu];
        parent[pu]=pv;
    }
    else{
        size[pu]+=size[pv];
        parent[pv]=pu;
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> parent(n);
        vector<int> size(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]){
                    unionbysize(i,j,parent,size);
                }
            }
        }
        int groups=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                groups++;
            }
        }
        return n-groups;
    }
};