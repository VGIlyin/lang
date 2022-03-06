#ifndef GOSLING_LEXER_H
#define GOSLING_LEXER_H

#include <list>
#include <string>
#include <regex>
#include "token.h"
#include "/home/sergei/CLionProjects/list_mv/list_mv.h" // мой лист

class Lexer {
private:
	static std::list<Token> tokens;
	static const std::pair<std::string, std::regex> DESCRIPTION_LECHEMS[];
	static const size_t DESC_LECHEMS_SIZE;
public:
	static void run(std::string);
	static std::list<Token>& get_list_token();
};

#endif //GOSLING_LEXER_H