class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        int start_l=0;
        int r=0;
        int ans=INT_MAX;
        int req=t.length();
        if(req>s.length()){
            return "";
        }
        unordered_map<char,int> mp;
        for(char &ch:t)
        {
           mp[ch]++;
        }
        for(r=0;r<s.length();r++){
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