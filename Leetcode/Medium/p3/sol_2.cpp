#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto cs = set<char>();

        int start = 0;
        int end = 0;
        int bStart = 0;
        int bEnd = 0;

        int maxLen = 0;
        int i = 0;
        for(i = 0; i < s.length(); i++) {
            auto result = cs.insert(s[i]);
            
            //char already exists?
            if(!result.second) {
                end = i;

                if( (end - start) > (bEnd - bStart) ) {
                    bEnd = end;
                    bStart = start;
                }

                start = start + 1;
                i = start - 1;
                cs.clear();
            }

            //cout << i << " " << s[i] << " " << result.second << " start " << start << endl;
        }

        //final check 
        end = i;   
        if( (end - start) > (bEnd - bStart) ) {
            bEnd = end;
            bStart = start;
        }

        //cout << s.substr(bStart,bEnd) << endl;
        return bEnd - bStart;
    }
};