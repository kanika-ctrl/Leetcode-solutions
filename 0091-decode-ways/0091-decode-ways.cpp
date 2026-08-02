class Solution {
public: 
    int solve(string &s,int idx,vector<int> &dp){
        if(idx==s.size()){
            return 1;
        }
        if(s[idx]=='0'){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int takeone=solve(s,idx+1,dp);
        int taketwo=0;
        if(idx+1<s.size()){
            int word=(s[idx]-'0')*10+(s[idx+1]-'0');
            if(word>=10 && word<=26){
                taketwo=solve(s,idx+2,dp);
            }
        }
        return dp[idx]=takeone+taketwo;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
         int ways=solve(s,0,dp);
        return ways;
    }
};