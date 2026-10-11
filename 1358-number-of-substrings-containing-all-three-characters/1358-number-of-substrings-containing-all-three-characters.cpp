class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int n=s.length();
        int ans=0;
        int freq[3]={0};
        int r=0;
        for( r=0;r<n;r++){
            freq[s[r]-'a']++;
            while(freq[0]!=0 && freq[1]!=0 && freq[2]!=0){
                ans+=n-r;
                freq[s[l]-'a']--;
                l++;
            }
        }
         while(r==n-1 && freq[0]!=0 && freq[1]!=0 && freq[2]!=0){
            ans+=n-r;
            freq[s[l]-'a']--;
            l++;
         }
        return ans;
    }
};