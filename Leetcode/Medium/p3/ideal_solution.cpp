#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int> alpha(255,-1);
        int l=0;
        int i=0;
        int maxcount=0;
        while(i<n){
             if(alpha[s[i]]!=-1&&alpha[s[i]]>=l){
                 l=alpha[s[i]]+1;
             }
            alpha[s[i]]=i;
             maxcount=max(maxcount,i-l+1);
              i++;
        }
        return maxcount;
    }
};