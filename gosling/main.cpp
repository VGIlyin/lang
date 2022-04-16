#include <iostream>
#include "lexer.h"
#include <fstream>
#include "Parser.h"

int main(int argc, char *argv[]) {

	std::fstream file;
	file.open("/home/sergei/CLionProjects/gosling/text.txt");

	if (file.is_open()) {
		// Лексер
		std::string line;
		while (!file.eof()) {
			std::getline(file, line);
			Lexer::run(line);
		}

		std::list<Token>::iterator it_tokens = Lexer::get_list_token().begin();

		for (;it_tokens != Lexer::get_list_token().end(); ++it_tokens) {
			std::cout << *it_tokens << '\n';
		}

		// Парсер
		Parser Parser(Lexer::get_list_token());

		try {
			if (!Parser.check()) {
				std::cout << "ошибка в парсере\n";
			}
		} catch (std::string exception_string) {
			std::cout << "error " << exception_string << '\n';
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

	return 0;
}
