class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mymap;
        for(int i=0;i<nums.size();i++){
            if(mymap.find(nums[i])!=mymap.end()){
                int index=mymap[nums[i]];
                int j=i+1;
                if(abs(j-index)<=k){
                    return true;
                }
            }
            mymap[nums[i]]=i+1;
        }
        
        return false;
    }
};