class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0&&x!=0)){
            return false;
        }
        int rev=0;
        while(rev<x){
            int ld=x%10;
            rev=rev*10+ld;
            x=x/10;
        }
        if(x==rev){
            return true;
        }
        if(x==rev/10){
            return true;
        }
        return false;
    }
};