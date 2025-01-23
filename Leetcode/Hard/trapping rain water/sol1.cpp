class Solution {
public:
   int trap(vector<int>& height) {
    int n = height.size();
    int totalWater = 0;

    for (int i = 0; i < n; i++) {
        // Find the maximum height to the left of the current bar
        int maxLeft = 0;
        for (int j = 0; j <= i; j++) {
            maxLeft = max(maxLeft, height[j]);
        }

        // Find the maximum height to the right of the current bar
        int maxRight = 0;
        for (int j = i; j < n; j++) {
            maxRight = max(maxRight, height[j]);
        }

        // Calculate water trapped at the current bar
        totalWater += min(maxLeft, maxRight) - height[i];
    }

    return totalWater;
    }
};