class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mymap;
        for(int i=0;i<nums.size();i++){
            mymap[nums[i]]++;
        }
        int ans=0;
        for(auto it:mymap){
          int freq=it.second;
          
            ans+=(freq*(freq+1)/2)-freq;
          
        }
        return ans;
    }
};