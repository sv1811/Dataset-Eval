// Dynamic Programming Solution
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (const string& left : dp[j]) {
                    for (const string& right : dp[i - 1 - j]) {
                        dp[i].push_back("(" + left + ")" + right);
                    }
                }
            }
        }
        return dp[n];
    }
};
