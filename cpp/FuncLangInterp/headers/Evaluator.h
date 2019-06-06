//#pragma once
#ifndef EVALUATOR_H
#define EVALUATOR_H

/* Класс Evaluator осуществялет вычисление/выполнение заданных в векторе лексем функций.
	- Вектор лексем передаётся на вход метода evaluate() через конструктор Evaluator();
	- Метод evaluate() выполняет вычисления и формирует строку окночательного результата (final_rez); 
	- Метод getRezult() возвращает итоговый результат в виде строки. */

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;
class Evaluator
{
public:
	Evaluator(vector<string>& in_vec); 
	string getRezult() { return final_rezult; }
private:
	void evaluate(vector<string>  in_vec);
	string compute_func(string func_name, vector<string> arg_vec);
	vector<string> get_last_arg(vector<string>& in_vec, unsigned n_args);
	string get_last_func(vector<string>& in_vec);
	bool isfunc(string str);
	bool isnumb(string str);
	vector<string> func_vec;	// вектор для хранения имён функций
	vector<string> arg_vec;		// вектор для хранения аргументов функций
	string final_rezult;		// строка для хранения окнончательного результата
	string tmp_rezult;			// строка для хранения промежуточного результата
};

#endif /* EVALUATOR_H */
