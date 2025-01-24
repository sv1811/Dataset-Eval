#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; --i) {
            int temp = 0;
            while(!st.empty() && st.top() < heights[i]) {
                ++temp;
                st.pop();
            }
            ans[i] = st.empty() ? temp : temp + 1;
            st.push(heights[i]);
        }

        return ans;
    }
};