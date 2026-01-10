class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool flag=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                flag=1;
            }
            if(nums[i]==0||nums[i]<0||nums[i]>n){
                nums[i]=1;
            }
        }
        if(flag==0){
            return 1;
        }
        for(int i=0;i<nums.size();i++){
            int index=abs(nums[i]);
            if(nums[index-1]<0){
                continue;
            }
            nums[index-1]*=-1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};