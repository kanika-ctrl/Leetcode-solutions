class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxs=0;
        int count=0;
        int n=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            else{
                maxs=max(maxs,count);
                count=0;
            }
        }
        if(count!=0){
            maxs=max(maxs,count);
        }
        return maxs;
    }
};