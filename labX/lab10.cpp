#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string file_input = "file_input.txt";
string file_output = "file_output.txt";


vector<int> GetCountersC(string inp_file_name, char c)
{
	ifstream inp;
	inp.open(inp_file_name, ios_base::in);
	if (!inp.is_open()) throw exception("[File can't open!]\n");
	cout << "[Открыт файл ввода]\n";

	string line;
	int counter;
	vector<int> vc;
	while (getline(inp, line, '\n'))
	{
		counter = 0;
		if (inp.eof())
			break;
		for (auto l : line)
			if (l == c) counter++;
		vc.push_back(counter);
		cout << "[Обработана строка: " << vc.size() << "]\n";
		cout << "[Результат обработки (количество символов): " << counter << " ]\n\n";
	}
	inp.close();
	cout << "[Файл ввода закрыт]\n\n\n";
	return vc;
}

void WriteInFile(string out_file_name, vector<int> vc)
{
	ofstream out;
	out.open(out_file_name, ios_base::out | ios_base::trunc);
	if (!out.is_open()) throw exception("[File can't open!]\n");
	cout << "[Открыт файл вывода]\n";

	for (auto count : vc)
	{
		out << count << "\n";
	}
	cout << "[Данные записаны]\n";
	out.close();
	cout << "[Файл вывода закрыт]\n";

}


int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		cout << "Введите символ для подсчета:\n";
		char c;
		scanf_s("%c", &c);

		vector<int> vc;
		vc = GetCountersC(file_input, c);
		WriteInFile(file_output, vc);
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

}