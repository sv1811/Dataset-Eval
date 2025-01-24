#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), l = 0, r = 0, ans = 0;
        unordered_map<char, int> mp;
    
    while (r < n) {
        if (mp[s[r]] == 0) {
            mp[s[r]]++;
            r++;
            ans = std::max(ans, r - l); 
        } else {
            mp[s[l]]--;
            l++;
        }
    }
    
    return ans;
    }
};