// Variant 3: Hash Map
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    unordered_map<int, int> map;
    
    for (int i = 0; i < numbers.size(); ++i) {
        int complement = target - numbers[i];
        if (map.count(complement)) {
            return {map[complement] + 1, i + 1};
        }
        map[numbers[i]] = i;
    }
    
    return {};
}
