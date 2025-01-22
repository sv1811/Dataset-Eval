// **Variant 3: Tabulation (Bottom-Up DP)**
int maxSumTabulation(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        int include = nums[i] + (i > 1 ? dp[i - 2] : 0);
        int exclude = dp[i - 1];
        dp[i] = max(include, exclude);
    }

    return dp[n - 1];
}
