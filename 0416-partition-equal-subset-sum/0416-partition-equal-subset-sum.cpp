class Solution {
public:
    bool check(vector<int> &nums,int idx,int target,vector<vector<int>> &dp){
        if(target==0){
            return 1;
        }
        if(nums.size()<=idx){
            return 0;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        bool take=0;
        if(target>=nums[idx]){
            take=check(nums,idx+1,target-nums[idx],dp);
        }
        bool skip=check(nums,idx+1,target,dp);
        return dp[idx][target]=take||skip;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int target=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        bool ans=check(nums,0,target,dp);
        return ans;
    }
};