#include "../headers/StrParser.h"

StrParser::StrParser(string input_str)
{
	to_write = "";
	parse_str(input_str);
}
//----------------------------------------------------------------------------------------------------
void StrParser::parse_str(string in) 
{
	char* str_p = &in[0];
	/* �������� ������, ������ ��������� ������������� ������ ��� ������ � �������������� ������ */
	for (; *str_p; str_p++) {
		if (*str_p == '\"') {
			/* �������� ������� �������, ���������� ���������� ��� ����������� ������� 
			� ������������� ������, ���� �� �������� ����������� ������� */
			str_p++;
			while (*str_p != '\"' && *str_p) {
				to_write += *str_p;
				str_p++;
			} 
			if (!*str_p) {
				cout << "ERROR: Closing symbol (\") is absent!" << endl;
				break;
			}
		}
		else if (isalpha(*str_p)) {
			to_write += *str_p;
			continue;
		}
		else if (*str_p == '-') {
			to_write += *str_p;
			continue;
		}
		else if (isdigit(*str_p)) {
			to_write += *str_p;
			continue;
		}
		else if (*str_p == '(' || *str_p == ')') {
			if (to_write.empty()) {
				to_write = *str_p;
			}
			else {
				lec_vec.push_back(to_write);
				to_write = *str_p;
			}
		}									
		if (!to_write.empty()) lec_vec.push_back(to_write);
		to_write.clear();
	}

	/*
	������ ��� �������� �.�. ������� ������ ����� �� ������������� ��������
	*/
	if (!to_write.empty()) {
		lec_vec.push_back(to_write);
		to_write.clear();
	}
	
}
