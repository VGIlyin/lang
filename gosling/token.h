#ifndef GOSLING_TOKEN_H
#define GOSLING_TOKEN_H
#include <string>
#include <ostream>

class Token {
private:
	std::string type;
	std::string value;
public:
	Token() = delete;
	Token(std::string, std::string);
	Token(Token const &other_token);
	std::string get_type();
	std::string get_value();
};

std::ostream& operator<<(std::ostream&, Token&);

#endif //GOSLING_TOKEN_H
