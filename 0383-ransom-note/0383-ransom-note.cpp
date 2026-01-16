class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mymap;
        for(auto it:magazine){
            mymap[it]++;
        }
        for(auto it:ransomNote){
            if(mymap[it]==0){
                return false;
            }
            mymap[it]--;
        }
        return true;
    }
};