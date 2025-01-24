class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers cannot be palindromes
        if (x < 0) {
            return false;
        }

        // Store the original value
        int original = x;

        // Reverse the integer
        long long reversed = 0;
        while (x != 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        // Compare the reversed integer to the original
        return original == reversed;
    }
};