#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int countUnique = 0, max_len = 0,i=0;
        unordered_map<char, int> hash;
        for(char c: s)
        {
            int foundInd = hash[c];
            if(foundInd==0)
            {
                ++countUnique;
                max_len =max(max_len, countUnique);
                hash[c] = i+1; 
            }
            else
            {
                countUnique = i-foundInd+1;
                hash.clear();
                for(int j =foundInd; j<i;++j)
                {
                    hash[s[j]] = j+1;
                }
                hash[c] = i+1; 
            }
            ++i;
           // cout<<countUnique<<" ";
        }
        return max(max_len, countUnique);
    }
};