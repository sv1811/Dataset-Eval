#include <vector>
#include <cmath>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    double sum = 0;
    for (int num : nums) sum += log10(abs(num));
    
    vector<int> res;
    for (int num : nums) {
        res.push_back(round(pow(10, sum - log10(abs(num)))));
    }
    return res;
}
