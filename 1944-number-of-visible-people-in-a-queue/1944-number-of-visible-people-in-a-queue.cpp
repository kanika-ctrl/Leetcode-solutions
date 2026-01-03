class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        stack<int>stk;
        int n=arr.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            int count=0;
            while(!stk.empty()&&stk.top()<arr[i]){
                count++;
                stk.pop();
            }
            if(!stk.empty()){
                count++;
            }
            ans[i]=count;
            stk.push(arr[i]);
        }
        return ans;
    }
};
