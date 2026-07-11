class Solution {
public:
int findparent(int u,vector<int> &parent){
    if(u==parent[u]) return u;
    return parent[u]=findparent(parent[u],parent);
}
void unionbysize(int u,int v,vector<int> &parent,vector<int> &size){
    int pu=findparent(u,parent);
    int pv=findparent(v,parent);
    if(size[pu]<size[pv]){
        size[pv]+=size[pu];
        parent[pu]=pv;
    }
    else{
        size[pu]+=size[pv];
        parent[pv]=pu;
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        vector<int> size(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int sz=connections.size();
        if(sz<n-1) return -1;
        int components=n;
        for(auto &edge:connections){
           if(findparent(edge[0],parent)!=findparent(edge[1],parent)){
            unionbysize(edge[0],edge[1],parent,size);
                    components--;
           }
        }
        return components-1;
    }
};