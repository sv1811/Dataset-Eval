#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp (s.size(), vector<bool>(s.size(), false));
        if(s.size()<1) return s;
        string longest{s[0]};
        for(int i(0);i<s.size();++i)
        {
            dp[i][i] = true;
        }
        for(int l(1);l<s.size();++l)
        {
            for(int i(0);i+l<s.size();++i)
            {
                //cout<<s.substr(i, l+1)<<endl;
                if(l>1) dp[i][i+l] = dp[i+1][i+l-1] && s[i]==s[i+l];
                else dp[i][i+l] = s[i] == s[i+l];
                if(dp[i][i+l]) longest = s.substr(i,l+1);
            }
        }
        // for(auto v:dp)
        // {
        //     for(auto vv:v)
        //     {
        //         cout<<vv<<' ';
        //     }
        //     cout<<endl;
        // }
        return longest;
    }
};