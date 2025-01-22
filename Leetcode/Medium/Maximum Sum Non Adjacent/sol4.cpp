// **Variant 4: Space-Optimized DP**
int maxSumSpaceOptimized(vector<int>& nums) {
    if (nums.empty()) return 0;

    int prev2 = 0, prev1 = 0;
    for (int num : nums) {
        int current = max(prev1, prev2 + num);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}