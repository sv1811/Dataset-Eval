#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        set<int> st;
        int l = 0, r =0, max_l = 0, len = 0;
        // cout<<s.size()<<" "<<st.count(s[r])<<" ";
        while(r < s.size())
        {
            if(st.count(s[r]) == 0)
            {
                cout<<"in here";
                st.insert(s[r]);
                max_l = max(max_l, r-l+1);
                r++;
            }else{
                st.erase(s[l]);
                l++;
            }
        }
        cout<<l<<" "<<r;
        return max_l;
    }
};