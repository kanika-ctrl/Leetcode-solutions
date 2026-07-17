class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int diff=target-nums[i];
            if(mp.find(diff)!=mp.end()){
                int j=mp[diff];
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            mp[nums[i]]=i;
        }
        ans.push_back(-1);
        return ans;
    }
};