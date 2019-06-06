#include "../headers/Evaluator.h"

Evaluator::Evaluator(vector<string>& in_vec) 
{
	evaluate(in_vec);
}
//--------------------------------------------------------------------------------
bool Evaluator::isfunc(string str) 
{
	if (str == "add" || str == "sub" || str == "mult" || str == "concat") return true;
	else return false;
}
//--------------------------------------------------------------------------------
bool Evaluator::isnumb(string str) 
{
	if (str[0] == '-' || isdigit(str[0])) {
		if (str.size() > 1) {
			for (decltype(str.size()) index = 1; index != str.size(); ++index)
				if (str[index] == '-' || isalpha(str[index])) { return false; }
		}
		return true;
	}
	else return false;
}
//--------------------------------------------------------------------------------
vector<string> Evaluator::get_last_arg(vector<string>& in_vec, unsigned n_args) 
{
	vector<string> out_vec;
	unsigned args_count = n_args;
	while (args_count != 0) {
		out_vec.push_back( in_vec.back() );
		in_vec.pop_back();
		--args_count;
	}
	return out_vec;
}
//--------------------------------------------------------------------------------
string Evaluator::get_last_func(vector<string>&  in_vec) 
{
	string out_str;
	out_str = in_vec.back();
	in_vec.pop_back();
	return out_str;
}
//--------------------------------------------------------------------------------
string Evaluator::compute_func(string func_name, vector<string> arg_vec) 
{
	int int_rezult = 0;
	string str_rezult;
	if (func_name == "add") {
		for (decltype(arg_vec.size()) index = 0; index != arg_vec.size(); ++index)
			int_rezult += atoi(arg_vec[index].c_str());
		return to_string(int_rezult);
	}
	else
	if (func_name == "sub") {
		int_rezult = atoi(arg_vec.back().c_str());
		for (decltype(arg_vec.size()) index = 0; index != arg_vec.size() - 1; ++index)
			int_rezult += atoi(arg_vec[index].c_str()) * (-1);
		return to_string(int_rezult);
	}
	else
	if (func_name == "mult") {
		int_rezult = atoi(arg_vec.back().c_str());
		for (decltype(arg_vec.size()) index = 0; index != arg_vec.size() - 1; ++index)
			int_rezult *= atoi(arg_vec[index].c_str());
		return to_string(int_rezult);
	}
	else
	if (func_name == "concat") {
		str_rezult = arg_vec.back();
		int size = arg_vec.size() - 2;
		while (size >= 0) {
			str_rezult += arg_vec[size];
			--size;
		}
		return str_rezult;   
	}
}
//--------------------------------------------------------------------------------
void Evaluator::evaluate(vector<string>  in_vec) 
{
  /* Т.к. наш примитивный функциональный язык в сущности практический является Польской нотацией (префиксной записью),
		можно обойтись без вычислительного дерева и выполнить расчёт "в лоб". Символ "(" будем использовать как маркер вызова новой функции, 
		т.е. встретив скобку будем откладывать вычисление прошлой функции. */
  auto it_beg = in_vec.begin();
  auto it_end = in_vec.end();
  unsigned args_counter = 0;	// переменная для хранения количества аргументов функций

  while (arg_vec.size() != 1) {
	  for (; it_beg != it_end; it_beg++) {
		  if (isfunc(*it_beg)) {
			  func_vec.push_back(*it_beg);
			  continue;
		  }
		  if (isnumb(*it_beg)) {
			  args_counter++;
			  arg_vec.push_back(*it_beg);
			  continue;
		  }
		  if (*it_beg == "(" ) {
			  // Вызов новой функции, обнуляем количество аргументов
			  args_counter = 0;
			  continue;
		  }
		  if (*it_beg == ")") {
			  // Выполняем вычисление последней функции и записываем новый аргумент в вектор
			  tmp_rezult = compute_func(get_last_func(func_vec), get_last_arg(arg_vec, args_counter));
			  arg_vec.push_back(tmp_rezult);
			  continue;
		  }
		  else { //значит строка (мат. операции со строками не предусмотрены)
			  arg_vec.push_back(*it_beg);
			  args_counter++;
			  continue;
		  }
		  tmp_rezult = compute_func(get_last_func(func_vec), get_last_arg(arg_vec, args_counter));
		  args_counter = 0;
		  arg_vec.push_back(tmp_rezult);
	  }
	  /* Если количство аргументов в векторе равно 1, то расчёт окончен, выходим из функции, в противном случае выполняем последнее вычисление */
	  if (arg_vec.size() == 1) {
		final_rezult = arg_vec.back();
		return;
	  }
	  else tmp_rezult = compute_func(get_last_func(func_vec), get_last_arg(arg_vec, arg_vec.size()));
	  arg_vec.push_back(tmp_rezult);
  }
  final_rezult = arg_vec.back();
}
//----------------------------------------------------------------------------------------------------
