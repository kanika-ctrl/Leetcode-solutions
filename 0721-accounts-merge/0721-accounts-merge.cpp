class Solution {
public:
int findparent(int u,vector<int> &parent){
    if(u==parent[u]) return u;
    return parent[u]=findparent(parent[u],parent);
}
void unionbysize(int u,int v,vector<int> &parent , vector<int> &size){
    int pv=findparent(v,parent);
    int pu=findparent(u,parent);
    if(pv==pu) return;
    if(size[pv]>size[pu]){
        size[pv]+=size[pu];
        parent[pu]=parent[pv];
    }
    else{
        size[pu]+=size[pv];
        parent[pv]=parent[pu];
    }
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int> parent(n);
        vector<int> size(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
       unordered_map<string,int> mp;
       for(int i=0;i<n;i++){
        for(int j=1;j<accounts[i].size();j++){
            if(mp.find(accounts[i][j])!=mp.end()){
                unionbysize(i,mp[accounts[i][j]],parent,size);
            }
            else{
                mp[accounts[i][j]]=i;
            }
        }
       }
       vector<string>merge[n];
       for(auto &it:mp){
        int node=findparent(it.second,parent);
        string mail=it.first;
        merge[node].push_back(mail);
       }
       vector<vector<string>> ans;
       for(int i=0;i<n;i++){
        if(merge[i].size()==0) continue;
         sort(merge[i].begin(),merge[i].end());
         vector<string> temp;
         temp.push_back(accounts[i][0]);
         for(auto &it:merge[i]){
            temp.push_back(it);
         }
         ans.push_back(temp);
       }
       return ans;
    }
};