class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int max=INT_MIN;
        int value=2;
        for(auto a:mp){
            int freq=a.second;
            if(max<freq){
              max=freq;
              value=a.first;
            }
        }
        return value;
    }
};