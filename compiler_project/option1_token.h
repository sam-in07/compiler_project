#ifndef OPTION1_TOKEN_H
#define OPTION1_TOKEN_H

#include <string>
#include <iostream>

enum TokenType {
    LET,
    IDENTIFIER,
    EQUAL,
    NUMBER,
    PLUS,
    PRINT,
    SEMICOLON,
    END_OF_FILE,
    UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
};

// Helper to convert enum to string
inline std::string tokenTypeToString(TokenType type) {
    switch (type) {
        case LET: return "LET";
        case IDENTIFIER: return "Identifier";
        case EQUAL: return "Assign value";
        case NUMBER: return "Number";
        case PLUS: return "arithmatic Op";
        case PRINT: return "Print";
        case SEMICOLON: return "End of line";
        case END_OF_FILE: return "EOF";
        case UNKNOWN: return "Unknown";
        default: return "UNKNOWN";
    }
}

// Operator overloading to print token nicely
inline std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << token.value << " --> " << tokenTypeToString(token.type);
    return os;
}

#endif