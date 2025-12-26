#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int tempVar = 1;

void generateTAC(string expr) {
    stack<string> st;
    for (int i = 0; i < expr.length(); ++i) {
        char c = expr[i];
        if (isspace(c)) continue;

        if (isalnum(c)) {
            st.push(string(1, c));
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string temp = "t" + to_string(tempVar++);
            cout << temp << " = " << op1 << " " << c << " " << op2 << endl;
            st.push(temp);
        }
    }
    string final = st.top(); st.pop();
    cout << "Result stored in: " << final << endl;
}

void runThreeAddress() {
    tempVar = 1;
    cout << "\nEnter an arithmetic expression (e.g., a=b+c*d): ";
    string expr;
    getline(cin, expr);

    size_t eq = expr.find('=');
    if (eq != string::npos) {
        string lhs = expr.substr(0, eq);
        string rhs = expr.substr(eq + 1);
        cout << "\nThree Address Code:\n";
        generateTAC(rhs);
        cout << lhs << " = t" << tempVar - 1 << endl;
    } else {
        cout << "Invalid expression format.\n";
    }
}