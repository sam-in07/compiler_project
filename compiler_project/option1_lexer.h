#ifndef OPTION1_LEXER_H
#define OPTION1_LEXER_H

#include <vector>
#include <string>
#include "option1_token.h"

std::vector<Token> tokenize(const std::string& input);

#endif