//#include <stdlib.h>
#include <iostream>
#include <string>

#include "../headers/StrParser.h"
#include "../headers/Evaluator.h"

using namespace std;

int main()
{
	string input_str;
	while (getline(cin, input_str))
	if (input_str.empty()) cout << "ERROR: Empty input!" << endl;
	else if (input_str == "quit") { exit(0); }
	else {
		StrParser parser(input_str);
		auto rez_lec_vec = parser.getLecVec();
		Evaluator evaluator(rez_lec_vec);
		cout << "> " << evaluator.getRezult() << endl;
	}
	return 0;
}
