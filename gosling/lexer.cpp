#include "lexer.h"

const std::pair<std::string, std::regex> Lexer::DESCRIPTION_LECHEMS[] = {
		std::make_pair("VAR", std::regex((R"([a-zA-Z_][A-Za-z0-1_]*)"))),
		std::make_pair("DIGIT", std::regex((R"([1-9][0-9]*)"))),
		std::make_pair("ASSIGN_OP", std::regex((R"([\=\+\-\*\/])"))),
		std::make_pair("STRING", std::regex((R"((^'[^']*))"))),
		//std::make_pair("METHOD", std::regex((R"((.[a-zA-Z_][a-zA-Z_0-9]*[(][[a-zA-Z_0-9]*][)]))"))),
};

const size_t Lexer::DESC_LECHEMS_SIZE = sizeof(DESCRIPTION_LECHEMS) / sizeof(std::pair<std::string, std::regex>);

std::list<Token> Lexer::tokens{};

void Lexer::run(std::string expression) {
	expression += " ";
	std::string lechema = "";
	std::string type_of_current_lechema;
	std::string type_last_of_lechema = "";

	for (int i = 0; i < expression.size(); i++) {
		lechema += expression[i];
		type_of_current_lechema = "";

		for (int j = 0; j < DESC_LECHEMS_SIZE; j++) {
			if (std::regex_match(lechema.data(), DESCRIPTION_LECHEMS[j].second)) {
				type_of_current_lechema = DESCRIPTION_LECHEMS[j].first;
				break;
			}
		}

		if (type_of_current_lechema.empty()) {
			if (!type_last_of_lechema.empty()) {
				if (type_last_of_lechema != "STRING") {
					tokens.emplace_back(Token(type_last_of_lechema, lechema.substr(0, lechema.size() - 1)));
					i--;
				} else {
					tokens.emplace_back(Token(type_last_of_lechema, lechema.substr(0, lechema.size())));
				}
			} else {
				if (lechema != " ") {
					tokens.emplace_back(Token("error", lechema));
					i--;
				}
			}

			lechema = "";
		}

		type_last_of_lechema = type_of_current_lechema;
	}

	if (type_of_current_lechema == "STRING") {
		tokens.emplace_back(Token("error", lechema));
	}
}

std::list<Token>& Lexer::get_list_token() {
	return tokens;
}
