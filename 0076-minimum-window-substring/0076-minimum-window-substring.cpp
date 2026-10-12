class Solution {
public:
    string minWindow(string s, string t) {
        int req=t.length();
        int n=s.length();
        if(req>n) return "";
        int l=0;
        int ans=INT_MAX;
        int start_l=0;
        unordered_map<char,int> mp;
        for(auto &ch:t){
            mp[ch]++;
        }
        for(int r=0;r<n;r++){
            if(mp[s[r]]>0){
                req--;
            }
            mp[s[r]]--;
            while(req==0){
                int currwid=r-l+1;
                if(ans>currwid){
                    ans=currwid;
                    start_l=l;
                }
                 mp[s[l]]++;
                if(mp[s[l]]>0){
                    req++;
                }
                l++;
            }
        }
        if(ans==INT_MAX) return "";
        return s.substr(start_l,ans);
    }
};