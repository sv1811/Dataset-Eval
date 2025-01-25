#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        int n = heights.size();

        stack<int>st;

        for(int i=0;i<n;i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i]) 
            {
                int index = st.top();
                st.pop();

                // Calculate area with heights[index] as the smallest height
                if (!st.empty()) 
                {
                    ans = max(ans, heights[index] * (i - st.top() - 1));
                } else 
                {
                    ans = max(ans, heights[index] * i);
                }
            }
              // Push the current index
              
                st.push(i);
            }
            // Process remaining elements in the stack
            while(!st.empty())
            {
            
              int index = st.top();
              st.pop();
              if (!st.empty())
               {
                ans = max(ans, heights[index] * (n - st.top() - 1));
               } 
               else 
               {
                ans = max(ans, heights[index] * n);
            }
        }
            return ans; 
    }
};