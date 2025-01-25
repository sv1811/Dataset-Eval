#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans=0,n=heights.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                int tp=st.top();
                st.pop();
                int h=heights[tp];
                int w=st.empty()?i:i-st.top()-1;
                ans=max(ans,h*w);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int tp=st.top();
            st.pop();
            int h=heights[tp];
            int w=st.empty()?n:n-st.top()-1;
            ans=max(ans,h*w);
        }
        return ans;
    }
};