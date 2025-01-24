// Variant 2: Using a Vector as a Stack
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int evalRPN(vector<string>& tokens) {
    vector<int> stack;
    for (const string& token : tokens) {
        if (isdigit(token.back())) {
            stack.push_back(stoi(token));
        } else {
            int b = stack.back(); stack.pop_back();
            int a = stack.back(); stack.pop_back();
            if (token == "+") stack.push_back(a + b);
            else if (token == "-") stack.push_back(a - b);
            else if (token == "*") stack.push_back(a * b);
            else if (token == "/") stack.push_back(a / b);
        }
    }
    return stack.back();
}
