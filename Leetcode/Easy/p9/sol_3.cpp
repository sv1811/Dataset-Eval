class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long long revN = 0;
        long long dup = x;

        while (x != 0) {
            int ld = x % 10;
            revN = revN * 10 + ld;
            x /= 10;
        }
        if (revN == dup) return true;
        else return false; 
        
    }
};