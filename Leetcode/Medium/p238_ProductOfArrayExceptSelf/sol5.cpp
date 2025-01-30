#include <vector>
using namespace std;

void compute(vector<int>& nums, vector<int>& res, int i, int prod) {
    if (i == nums.size()) return;
    int temp = nums[i];
    res[i] = prod;
    compute(nums, res, i + 1, prod * temp);
    res[i] *= (i > 0 ? nums[i - 1] : 1);
}

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 1);
    compute(nums, res, 0, 1);
    return res;
}
