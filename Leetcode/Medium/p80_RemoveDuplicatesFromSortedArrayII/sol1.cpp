#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) return n;

    int writeIndex = 1, count = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            count++;
        } else {
            count = 1;
        }
        if (count <= 2) {
            nums[writeIndex++] = nums[i];
        }
    }
    return writeIndex;
}
