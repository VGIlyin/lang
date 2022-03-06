#include <iostream>
#include <string>
#include "lexer.h"
#include <fstream>

int main(int argc, char *argv[]) {

	std::fstream file;
	file.open("/home/sergei/CLionProjects/gosling/text.txt");

	if (file.is_open()) {
		std::string line;
		while (!file.eof()) {
			std::getline(file, line);
			Lexer::run(line);
		}
	} else {
		std::cout << "файл c кодом не найден\n";
	}

	/*
	Lexer::run(std::string("new_str = 'stringa' + old_str"));

	std::list<Token>::iterator it_tokens = Lexer::get_list_token().begin();

	for (;it_tokens != Lexer::get_list_token().end(); ++it_tokens) {
		std::cout << *it_tokens << '\n';
	}

	*/

	/*
	for (int i = 0; i < argc; i++) {
		Lexer::run(std::string(argv[i]));
	}

	*/

	std::list<Token>::iterator it_tokens = Lexer::get_list_token().begin();

	for (;it_tokens != Lexer::get_list_token().end(); ++it_tokens) {
		std::cout << *it_tokens << '\n';
	}

	return 0;
}
