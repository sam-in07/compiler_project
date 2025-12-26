#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

int tempVarCount = 1;

string newTemp() {
    return "t" + to_string(tempVarCount++);
}

int precedence(char op) {
    if(op == '+'||op == '-') return 1;
    if(op == '*'||op == '/') return 2;
    return 0;
}

string generate3AC(string expr) {
    stack<char> operators;
    stack<string> operands;
    string result;

    for (int i = 0; i < expr.length(); i++) {
        char token = expr[i];

        if (isspace(token)) continue;

        if (isalnum(token)) {
            string operand(1, token);
            operands.push(operand);
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                string b = operands.top(); operands.pop();
                string a = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                string temp = newTemp();
                result += temp + " = " + a + " " + op + " " + b + "\n";
                operands.push(temp);
            }
            if (!operators.empty()) operators.pop(); // remove '('
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                string b = operands.top(); operands.pop();
                string a = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                string temp = newTemp();
                result += temp + " = " + a + " " + op + " " + b + "\n";
                operands.push(temp);
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        string b = operands.top(); operands.pop();
        string a = operands.top(); operands.pop();
        char op = operators.top(); operators.pop();
        string temp = newTemp();
        result += temp + " = " + a + " " + op + " " + b + "\n";
        operands.push(temp);
    }

    return result;
}

void runOption2() {
    cout << "===== Three Address Code Generator =====" << endl;
    cout << "Enter a simple arithmetic expression (e.g., a = b + c * d):\n";
    string input;
    getline(cin, input);

    // Split around '='
    size_t eq = input.find('=');
    if (eq == string::npos) {
        cout << "Invalid expression. Must contain '='.\n";
        return;
    }

    string lhs = input.substr(0, eq);
    string rhs = input.substr(eq + 1);

    string code = generate3AC(rhs);
    string finalResult = lhs + " = " + (tempVarCount > 1 ? "t" + to_string(tempVarCount - 1) : rhs);

    cout << "\nThree Address Code:\n";
    cout << code;
    cout << finalResult << endl;
}