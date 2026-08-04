class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,-1);
        int l=0;
        int ans=0;
        for(int r=0;r<s.size();r++){
            if(freq[s[r]]>=l){
                l=freq[s[r]]+1;
            }
            freq[s[r]]=r;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};