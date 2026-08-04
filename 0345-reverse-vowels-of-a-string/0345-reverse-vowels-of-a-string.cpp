class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> st={'a','e','i','o','u','A','E','I','O','U'};
        int l=0;
        int r=s.size()-1;
        while(l<r){
            while(l<r&&st.find(s[l])==st.end()){
                l++;
            }
            while(l<r&&st.find(s[r])==st.end()){
                r--;
            }
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};