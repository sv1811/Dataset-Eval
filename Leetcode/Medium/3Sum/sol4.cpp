// **Variant 4: Recursive Backtracking**
void findTriplets(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == 3) {
        if (current[0] + current[1] + current[2] == 0) {
            result.push_back(current);
        }
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        current.push_back(nums[i]);
        findTriplets(i + 1, nums, current, result);
        current.pop_back();
    }
}

vector<vector<int>> threeSumBacktracking(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    findTriplets(0, nums, current, result);
    return result;
}
