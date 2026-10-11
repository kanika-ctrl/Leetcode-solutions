class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int n=nums.size();
        int r=n-1;
        int ans=sum;
        for(int i=k-1;i>=0;i--){
            sum-=nums[i];
            sum+=nums[r];
            r--;
            ans=max(ans,sum);
        }
        return ans;
    }
};