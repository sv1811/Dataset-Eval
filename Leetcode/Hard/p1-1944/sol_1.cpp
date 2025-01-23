#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        
        // O(n). Monotonic queue & binary search
        int n = heights.size();
        vector<int> vResult(n, 0);
        vector<int> st;
        st.push_back(heights.back());

        for (int i = n - 2; i >= 0; i--)
        {
            auto it = std::upper_bound(st.rbegin(), st.rend(), heights[i]);
            vResult[i] = (it == st.rend()) ? st.size() : (it - st.rbegin() + 1);

            while (!st.empty() && heights[i] > st.back())
            {
                st.pop_back();
            }

            st.push_back(heights[i]);
        }

        return vResult;
    }
};