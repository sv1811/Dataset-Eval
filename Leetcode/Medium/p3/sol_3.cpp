#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int pos = 0;
        int max=0;
        int cur =0;
        int length = s.length();
        int streak_start = 0;
        bool end_pos = false;

        for (int i=0;i<length;i++){
            cur = 0;
            end_pos=false;
            while (!end_pos && (i+cur)<=length ){
                for (int ii=0;ii<cur;ii++){
                    if (s[i+ii] == s[cur+i]){
                        end_pos=true;
                    }
                }
                cur++;
            }
            cur--;
            if (cur>max){
                max=cur;
            }
        }

        return max;
    }
};