class Solution {
public:
    bool isPalindrome(int x) {
        int c=x;
        int r;
        long long sum=0;
        while(c>0){
            r=c%10;
            c=c/10;
            sum=sum*10+r;
        }
        if (sum==x) return true;
        else return false;     
    }
};