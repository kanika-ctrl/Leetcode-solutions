class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>stk;
        int second=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            while(!stk.empty()&&stk.top()<nums[i]){
                second=stk.top();
                stk.pop();
            }
            if(nums[i]<second){
                return true;
            }
            stk.push(nums[i]);
        }
        return false;
    }
};