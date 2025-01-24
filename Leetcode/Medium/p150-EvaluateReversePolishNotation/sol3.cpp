// Variant 3: Using Recursion
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int evalRPN(vector<string>& tokens, int& index) {
    string token = tokens[index--];
    if (isdigit(token.back())) {
        return stoi(token);
    } else {
        int b = evalRPN(tokens, index);
        int a = evalRPN(tokens, index);
        if (token == "+") return a + b;
        else if (token == "-") return a - b;
        else if (token == "*") return a * b;
        else if (token == "/") return a / b;
    }
    return 0;
}

int evalRPN(vector<string>& tokens) {
    int index = tokens.size() - 1;
    return evalRPN(tokens, index);
}
