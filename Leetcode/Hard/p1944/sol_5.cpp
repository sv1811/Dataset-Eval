#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) 
    {
        vector<int> ans(heights.size());
        stack<int> st;

        for(int i=heights.size()-1; i>=0; i--)
        {
            int smaller=0;
            while(!st.empty() and st.top() <= heights[i]) ++smaller, st.pop();

            ans[i] = smaller + (st.size() > 0 ? 1:0);
            st.push(heights[i]);
        }

        return ans;
    }
};