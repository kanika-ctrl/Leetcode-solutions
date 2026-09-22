class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res={{1}};
        for(int i=0;i<numRows-1;i++){
            vector<int> temp={{0}};
            for(int x:res.back()){
                temp.push_back(x);
            }
            temp.push_back(0);
            vector<int> row;
            for(int j=0;j<res.back().size()+1;j++){
                row.push_back(temp[j]+temp[j+1]);
            }
            res.push_back(row);
        }
        return res;
    }
};