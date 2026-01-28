class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        vector<int> ans;
        while(l<=r){
            int sum=nums[l]+nums[r];
            if(l<=r&&target>sum){
                l++;
            }
            else if(l<=r&&target<sum){
                r--;
            }
            else if(target==sum){
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
        }
        return ans;
    }
};