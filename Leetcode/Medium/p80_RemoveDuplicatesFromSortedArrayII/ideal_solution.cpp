#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int index = 0;
    for (int num : nums) {
        if (index < 2 || num != nums[index - 2]) {
            nums[index++] = num;
        }
    }
    return index;
}
