class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int res=0;
        int zeros=0;
        int r=0;
        for(r=0;r<nums.size();r++){
            if(nums[r]==0){
                zeros++;
                while(l<nums.size()&&zeros>k){
                    res=max(res,r-l);
                    if(l<nums.size()&&nums[l]==0){
                        zeros--;
                    }
                    l++;
                }
            }
        }
        res=max(res,r-l);
        return res;
    }
};