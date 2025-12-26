#include "option1_parser.h"
#include <iostream>

bool parse(const std::vector<Token>& tokens) {
    if (tokens.size() < 5) {
        std::cout << "Invalid statement\n";
        return false;
    }

    if (tokens[0].type == LET &&
        tokens[1].type == IDENTIFIER &&
        tokens[2].type == EQUAL &&
        tokens[3].type == NUMBER &&
        tokens[4].type == SEMICOLON) {
        std::cout << "Valid let statement\n";
        return true;
    }

    std::cout << "Invalid statement\n";
    return false;
}

bool isValidStatement(const std::vector<Token>& tokens) {
    return parse(tokens);
}