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
	cout << "[������ ���� �����]\n";

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
		cout << "[���������� ������: " << vc.size() << "]\n";
		cout << "[��������� ��������� (���������� ��������): " << counter << " ]\n\n";
	}
	inp.close();
	cout << "[���� ����� ������]\n\n\n";
	return vc;
}

void WriteInFile(string out_file_name, vector<int> vc)
{
	ofstream out;
	out.open(out_file_name, ios_base::out | ios_base::trunc);
	if (!out.is_open()) throw exception("[File can't open!]\n");
	cout << "[������ ���� ������]\n";

	for (auto count : vc)
	{
		out << count << "\n";
	}
	cout << "[������ ��������]\n";
	out.close();
	cout << "[���� ������ ������]\n";

}


int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		cout << "������� ������ ��� ��������:\n";
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