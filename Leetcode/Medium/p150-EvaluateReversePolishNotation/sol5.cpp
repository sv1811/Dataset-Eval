// Variant 5: Using a Stack with Switch-Case
#include <vector>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> stack;
    for (const string& token : tokens) {
        if (isdigit(token.back())) {
            stack.push(stoi(token));
        } else {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            switch (token[0]) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }
    return stack.top();
}
