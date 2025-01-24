// Variant 2: Binary Search
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size(); ++i) {
        int low = i + 1, high = numbers.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (numbers[mid] == target - numbers[i]) {
                return {i + 1, mid + 1};
            } else if (numbers[mid] < target - numbers[i]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    
    return {};
}
