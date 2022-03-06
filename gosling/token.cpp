#include "token.h"

Token::Token(std::string type, std::string value) {
	this->type = type;
	this->value = value;
}

Token::Token(Token const &other_token) {
	this->type = other_token.type;
	this->value = other_token.value;
}

std::string Token::get_type() {
	return type;
}

std::string Token::get_value() {
	return value;
}


std::ostream& operator<<(std::ostream &os, Token &token) {
	os << "{Token: type = " << token.get_type() << ", lechema = " << token.get_value() << "}";
	return os;
}
