//#pragma once
#ifndef STRPARSER_H
#define STRPARSER_H

/*  Класс StrParser осуществялет разбор входной строки на лексемы.
	- Входная строка передаётся в метод parse_str через конструктор StrParser();
	- Метод parse_str разбирает входную строку на отдельные лексемы и формирует вектор лексем (lec_vec);
	- Метод getLecVec() возвращает итоговый вектор лексем. */

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;
class StrParser 
{
public:
	StrParser(string input_str); 
	vector<string> getLecVec() { return lec_vec; }
private:
	string to_write;			// промежуточная строка для записи в результирующий вектор
	vector<string> lec_vec;		// результат работы - вектор лексем
	void parse_str(string in);
};

#endif /* STRPARSER_H */
