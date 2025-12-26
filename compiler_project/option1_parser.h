#ifndef OPTION1_PARSER_H
#define OPTION1_PARSER_H

#include <vector>
#include "option1_token.h"

bool parse(const std::vector<Token>& tokens);
bool isValidStatement(const std::vector<Token>& tokens);

#endif