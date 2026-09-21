class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        vector<int> prefixsum(n);
        mp[0]++;
        prefixsum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+nums[i];
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            int diff=prefixsum[i]-k;
            if(mp.find(diff)!=mp.end()){
                 cnt+=mp[diff];
            }
            mp[prefixsum[i]]++;
        }
        return cnt;
    }
};