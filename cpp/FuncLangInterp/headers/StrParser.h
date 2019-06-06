//#pragma once
#ifndef STRPARSER_H
#define STRPARSER_H

/*  ����� StrParser ������������ ������ ������� ������ �� �������.
	- ������� ������ ��������� � ����� parse_str ����� ����������� StrParser();
	- ����� parse_str ��������� ������� ������ �� ��������� ������� � ��������� ������ ������ (lec_vec);
	- ����� getLecVec() ���������� �������� ������ ������. */

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
	string to_write;			// ������������� ������ ��� ������ � �������������� ������
	vector<string> lec_vec;		// ��������� ������ - ������ ������
	void parse_str(string in);
};

#endif /* STRPARSER_H */
