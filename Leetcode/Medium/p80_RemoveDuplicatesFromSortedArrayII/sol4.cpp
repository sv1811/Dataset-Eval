#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int k = 2;
    if (nums.size() <= k) return nums.size();

    int index = k;
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] != nums[index - k]) {
            nums[index++] = nums[i];
        }
    }
    return index;
}
