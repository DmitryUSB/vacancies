//#pragma once
#ifndef EVALUATOR_H
#define EVALUATOR_H

/* ����� Evaluator ������������ ����������/���������� �������� � ������� ������ �������.
	- ������ ������ ��������� �� ���� ������ evaluate() ����� ����������� Evaluator();
	- ����� evaluate() ��������� ���������� � ��������� ������ �������������� ���������� (final_rez); 
	- ����� getRezult() ���������� �������� ��������� � ���� ������. */

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
	vector<string> func_vec;	// ������ ��� �������� ��� �������
	vector<string> arg_vec;		// ������ ��� �������� ���������� �������
	string final_rezult;		// ������ ��� �������� ��������������� ����������
	string tmp_rezult;			// ������ ��� �������� �������������� ����������
};

#endif /* EVALUATOR_H */
