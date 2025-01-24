class Solution {
public:
    bool isPalindrome(int x) {
        long long int sum=0,rev, org = x;

        while(x != 0){
            rev = x % 10;
            sum = (sum * 10) + rev;
            x /= 10;
        }
        
        if(sum != org || org < 0){
            return false;
        }
        else{
            return true;
        }
    }
};