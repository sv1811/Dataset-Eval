#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0, n = heights.size();
        vector<int> H;
        heights.push_back(0);
        for (int i = 0; i <= n; i++) {
            while (!H.empty() && heights[H.back()] >= heights[i]) {
                int height = heights[H.back()];
                H.pop_back();
                int leftIndex = (H.empty()) ? -1 : H.back();
                area = max(area, height * (i - leftIndex - 1));
            }
            H.push_back(i);
        }
        return area;
    }
};