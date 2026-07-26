class Solution {
public:
    int dpmoney(vector<int> &dp,vector<int> &nums,int n){
        if(n==0){
            return nums[0];
        }
        if(n<0) return 0;
        if(dp[n]!=-1){
            return dp[n];
        }
        int theft=nums[n]+dpmoney(dp,nums,n-2);
        int skip=dpmoney(dp,nums,n-1);
        dp[n]=max(skip,theft);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int i=n-1;
        int money=dpmoney(dp,nums,i);
        return money;
    }
};