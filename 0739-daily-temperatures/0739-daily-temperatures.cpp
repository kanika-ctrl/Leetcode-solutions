class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,0);
        stack<int>stk;
        for(int i=0;i<n;i++){
            while(!stk.empty()&&arr[stk.top()]<arr[i]){
                int index=stk.top();
                stk.pop();
                ans[index]=i-index;
            }
            stk.push(i);
        }
        return ans;
    }
};