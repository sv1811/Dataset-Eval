#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int count = 1;
    int j = 1;
    for (int i = 1; i < nums.size(); i++) {
        count = (nums[i] == nums[i - 1]) ? count + 1 : 1;
        if (count <= 2) {
            nums[j++] = nums[i];
        }
    }
    return j;
}
