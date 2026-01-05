class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>stk;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0||stk.empty()){
               stk.push(arr[i]);
            }
            else if(!stk.empty()&&stk.top()>0&&arr[i]<0){
                while(!stk.empty()&&stk.top()>0&&stk.top()<abs(arr[i])){
                    stk.pop();
                }
                if(!stk.empty()&&stk.top()<0&&arr[i]<0){
                    stk.push(arr[i]);
                }
                else if(!stk.empty()&&stk.top()==abs(arr[i])){
                    stk.pop();
                }
                else if(!stk.empty()&&stk.top()>abs(arr[i])){
                    continue;
                }
                else{
                    stk.push(arr[i]);
                }
            }
            else{
            stk.push(arr[i]);
            }
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};