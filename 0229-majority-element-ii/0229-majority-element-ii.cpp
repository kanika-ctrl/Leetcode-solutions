class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int nums1=-1;
        int votes1=0;
        int nums2=-1;
        int votes2=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums1==nums[i]){
                votes1++;
            }
            else if(nums2==nums[i]){
                votes2++;
            }
            else if(votes1==0){
                nums1=nums[i];
                votes1++;
            }
            else if(votes2==0){
                nums2=nums[i];
                votes2++;
            }
            else{
                votes1--;
                votes2--;
            }
        }
        int count1=0;
        int count2=0;
         for(int i=0;i<n;i++){
            if(nums[i]==nums1){
                count1++;
            }
            else if(nums[i]==nums2){
                count2++;
            }
         }

        if(count1>n/3 && count2>n/3){
            ans.push_back(nums1);
            ans.push_back(nums2);
        }
        else if(count1>n/3){
            ans.push_back(nums1);
        }
        else if(count2>n/3){
            ans.push_back(nums2);
        }
        return ans;
    }
};