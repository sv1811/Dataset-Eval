#include <string>
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string str = std::to_string(x);
        std::string reverse;
        int size = str.length();
        for (int i = size-1; i >=0; i--){
            reverse.push_back(str[i]);
        }
        return (str==reverse);
    }
};