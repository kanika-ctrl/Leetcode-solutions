class Solution {
public:
    int totalFruit(vector<int>& nums) {
        //your code goes here
        int l=0;
        int r=0;
        int ans=0;
        unordered_map<int,int> mp;
        for(r=0;r<nums.size();r++){
            mp[nums[r]]++;
           while(mp.size()>2){
            mp[nums[l]]--;
            if(mp[nums[l]]==0){
                mp.erase(nums[l]);
            }
            l++;
           }
           if(mp.size()<=2){
            ans=max(ans,r-l+1);
           }
        }
        return ans;
    
    }
};