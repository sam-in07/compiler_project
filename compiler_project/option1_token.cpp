#include "option1_token.h"

std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << token.value;
    return os;
}