// **Variant 1: Recursive Approach (Brute Force)**
int maxSumRecursive(vector<int>& nums, int index) {
    if (index < 0) return 0;
    return max(maxSumRecursive(nums, index - 1), nums[index] + maxSumRecursive(nums, index - 2));
}