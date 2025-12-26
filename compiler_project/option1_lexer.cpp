#include "option1_lexer.h"
#include <cctype>

std::vector<Token> tokenize(const std::string& input) {
    std::vector<Token> tokens;
    size_t i = 0;
    while (i < input.length()) {
        if (isspace(input[i])) {
            i++;
            continue;
        }

        if (input.compare(i, 3, "let") == 0) {
            tokens.push_back({LET, "let"});
            i += 3;
            continue;
        }
        if (input.compare(i, 5, "print") == 0) {
            tokens.push_back({PRINT, "print"});
            i += 5;
            continue;
        }
        if (isalpha(input[i]) || input[i] == '_') {
            std::string id;
            while (i < input.length() && (isalnum(input[i]) || input[i] == '_')) {
                id += input[i++];
            }
            tokens.push_back({IDENTIFIER, id});
            continue;
        }
        if (isdigit(input[i])) {
            std::string num;
            while (i < input.length() && isdigit(input[i])) {
                num += input[i++];
            }
            tokens.push_back({NUMBER, num});
            continue;
        }
        if (input[i] == '=') {
            tokens.push_back({EQUAL, "="});
            i++;
            continue;
        }
        if (input[i] == '+') {
            tokens.push_back({PLUS, "+"});
            i++;
            continue;
        }
        if (input[i] == ';') {
            tokens.push_back({SEMICOLON, ";"});
            i++;
            continue;
        }
        // Unknown token
        tokens.push_back({UNKNOWN, std::string(1, input[i])});
        i++;
    }
    tokens.push_back({END_OF_FILE, ""});
    return tokens;
}