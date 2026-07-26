class Solution {
public:
    int dpmoney(vector<int> &nums,vector<int> &dp,int i,int j){
        if(i==j){
            return nums[i];
        }
        if(i>j){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int steal=nums[i]+dpmoney(nums,dp,i+2,j);
        int skip=dpmoney(nums,dp,i+1,j);
        dp[i]=max(steal,skip);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp(n,-1);
        int ans1=dpmoney(nums,dp,0,n-2);
        for(int i=0;i<n;i++){
            dp[i]=-1;
        }
        int ans2=dpmoney(nums,dp,1,n-1);
        return max(ans1,ans2);
    }
};