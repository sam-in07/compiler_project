#include <iostream>
#include "option1_lexer.h"
#include "option1_parser.h"

using namespace std;

void runOption1() {
    string inputLine;
    cout << "\nEnter multiple lines of code (type END to stop):\n";
    while (true) {
        getline(cin >> ws, inputLine);
        if (inputLine == "END") break;

        vector<Token> tokens = tokenize(inputLine);
        // cout << "Tokens: \n";
        // for (auto &token : tokens) cout << token << " \n";
        // cout << "\n";

        cout << "\nTokens:\n";
for (auto &token : tokens) {
    cout << token.value << " token = ";
    switch (token.type) {
        case LET: cout << "LET"; break;
        case IDENTIFIER: cout << "Identifier"; break;
        case EQUAL: cout << "Assign value"; break;
        case NUMBER: cout << "Number"; break;
        case PLUS: cout << "Arithmatic Op Plus"; break;
        case PRINT: cout << "Print"; break;
        case SEMICOLON: cout << "End of line"; break;
        case END_OF_FILE: cout << "END_OF_FILE"; break;
        default: cout << "Unknown"; break;
    }
    cout << endl;
}

        if (isValidStatement(tokens))
            cout << " Valid Statement\n";
        else
            cout << " Invalid Statement\n";
    }
}