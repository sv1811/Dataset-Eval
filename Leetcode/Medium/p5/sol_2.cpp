#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int max_len = 0;
        for(int i=0;i<n;i++) {
            dp[i][i]=true;
            max_len = 1;
        }

        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) {
                dp[i][i+1] = true;
                max_len = 2;
                start = i;
            }
        }
        
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j = i+k-1;
                if(dp[i+1][j-1] and s[i]==s[j]){
                    dp[i][j] = true; 
                    start = i;
                    max_len = k;
                }
            }
        }

        return s.substr(start, max_len);

    }
};