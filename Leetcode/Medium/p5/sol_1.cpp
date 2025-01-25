#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        int max_len = 1;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = true;
            for (int j = 0; j < i; ++j) {
                if (s[i] == s[j] && (i - j <= 2 || dp[j+1][i-1])) {
                    dp[j][i] = true;
                    if (i - j + 1 > max_len) {
                        max_len = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};