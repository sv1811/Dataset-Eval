// **Variant 2: Recursive with Memoization**
int maxSumMemoHelper(vector<int>& nums, int index, unordered_map<int, int>& memo) {
    if (index < 0) return 0;
    if (memo.find(index) != memo.end()) return memo[index];

    memo[index] = max(maxSumMemoHelper(nums, index - 1, memo), nums[index] + maxSumMemoHelper(nums, index - 2, memo));
    return memo[index];
}

int maxSumMemoization(vector<int>& nums) {
    unordered_map<int, int> memo;
    return maxSumMemoHelper(nums, nums.size() - 1, memo);
}