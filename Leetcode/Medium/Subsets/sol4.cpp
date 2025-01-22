// **Variant 4: Divide and Conquer**
vector<vector<int>> subsetsDivideAndConquerHelper(vector<int>& nums, int start, int end) {
    if (start > end) return { { } };

    vector<vector<int>> subsets = subsetsDivideAndConquerHelper(nums, start + 1, end);
    int n = subsets.size();
    for (int i = 0; i < n; ++i) {
        vector<int> subset = subsets[i];
        subset.push_back(nums[start]);
        subsets.push_back(subset);
    }
    return subsets;
}

vector<vector<int>> subsetsDivideAndConquer(vector<int>& nums) {
    return subsetsDivideAndConquerHelper(nums, 0, nums.size() - 1);
}