#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

string path_txtintxt = "txtintxt.txt";
string path_txtinbin = "txtinbin.txt";
string path_bin = "bin.txt";

class Student
{
public:
	Student(string name, int GroupNumber, double GPA)
	{
		this->name = name;
		this->GroupNumber = GroupNumber;
		this->GPA = GPA;
	}
	Student()
	{
		GroupNumber = 0;
		GPA = 0;
		name = "";
	}

	void GetInfo()
	{
		cout << "Name = " << name << endl;
		cout << "Group Number = " << GroupNumber << endl;
		cout << "Grade point average = " << GPA << endl << endl;
	}
	void AddStudent(string name, int GroupNumber, double GPA)
	{
		this->name = name;
		this->GroupNumber = GroupNumber;
		this->GPA = GPA;
	}
	void Set_name(string name) { this->name = name; }
	string Get_name() { return name; }
	void Set_GroupNumber(double GPA) { this->GPA = GPA; }
	double Get_GPA() { return GPA; }

	
	friend ostream& operator << (ostream& os, const Student& st);
	friend istream& operator >> (istream& is, Student& st);
	friend void write_binary(vector<Student>& vs, const char* file_name, bool isBin);
	friend void read_binary(vector<Student>& vs, const char* file_name, bool isBin);

private:
	int GroupNumber;
	double GPA;
	string name;
};

void write_txt(vector<Student>&, const char*);
void read_txt(const char*);
void read_symbols_revers(const char*);
void del_name_and_write(string, const char*);
void search_name(string, const char*);
void search_name(vector<Student>, string);
vector<Student> del_name(vector<Student>, string);


void work_with_txtintxt(vector<Student>& vs, const char* path)
{
	cout << "[Пошла запись в файл]\n";
	write_txt(vs, path);
	cout << "[Запись в файл заверешена]\n";

	cout << "[Функция вывода в прямом порядке]\n";
	read_txt(path);
	cout << endl;

	cout << "[Функция вывода в обратном порядке]\n";
	read_symbols_revers(path);
	cout << endl;

	cout << "[Функция поиска по ключевому слову]\n";
	string keyword;
	cout << "Введите ключевое слово: ";
	cin.clear();
	rewind(stdin);
	getline(cin, keyword);
	search_name(keyword, path);
	cout << endl;

	cout << "[Функция удаления в файле по ключевому слову]\n";
	cout << "Введите ключевое слово: ";
	getline(cin, keyword);
	del_name_and_write(keyword, path);
	cout << endl;
	cout << "[Работа с файлом заверешена]\n";
}

void work_with_txtinbin(vector<Student>& vs, const char* path)
{
	cout << "[Пошла запись в файл]\n";
	write_binary(vs, path, false);
	cout << "[Запись в файл заверешена]\n";

	cout << "[Функция вывода в прямом порядке]\n";
	vector<Student> ms;
	read_binary(ms, path, false);
	for(auto value : ms)
	{
		value.GetInfo();
	}
	cout << endl;

	cout << "[Функция вывода в обратном порядке]\n";
	for (int i = ms.size() - 1; i > -1; i--)
		ms[i].GetInfo();
	cout << endl;

	cout << "[Функция поиска по ключевому слову]\n";
	string keyword;
	cout << "Введите ключевое слово: ";
	cin.clear();
	rewind(stdin);
	getline(cin, keyword);
	search_name(ms, keyword);
	cout << endl;

	cout << "[Функция удаления в файле по ключевому слову]\n";
	cout << "Введите ключевое слово: ";
	cin.clear();
	rewind(stdin);
	getline(cin, keyword);
	ms = del_name(ms, keyword);
	write_binary(ms, path, false);
	cout << endl;
	cout << "[Работа с файлом заверешена]\n";
}

void work_with_bininbin(vector<Student>& vs, const char* path)
{
	cout << "[Пошла запись в файл]\n";
	write_binary(vs, path, true);
	cout << "[Запись в файл заверешена]\n";

	cout << "[Функция вывода в прямом порядке]\n";
	vector<Student> ms;
	read_binary(ms, path, true);
	for (auto value : ms)
	{
		value.GetInfo();
	}
	cout << endl;

	cout << "[Функция вывода в обратном порядке]\n";
	for (int i = ms.size() - 1; i > -1; i--)
		ms[i].GetInfo();
	cout << endl;

	cout << "[Функция поиска по ключевому слову]\n";
	string keyword;
	cout << "Введите ключевое слово: ";
	cin.clear();
	rewind(stdin);
	getline(cin, keyword);
	search_name(ms, keyword);
	cout << endl;

	cout << "[Функция удаления в файле по ключевому слову]\n";
	cout << "Введите ключевое слово: ";
	cin.clear();
	rewind(stdin);
	getline(cin, keyword);
	ms = del_name(ms, keyword);
	write_binary(ms, path, true);
	cout << endl;
	cout << "[Работа с файлом заверешена]\n";
}

int main()
{
	setlocale(LC_ALL, "rus");
	vector<Student> vs;

	cout << "Получить новых студентов?\n";
	string answer;
	cin >> answer;
	if (answer == "да" or answer == "yes")
	{
		int count_students = 0;
		cout << "Введите количество студентов (> 4)\n";
		while (count_students < 1)
		{
			cin >> count_students;
			cin.clear();
			rewind(stdin);
		}
		Student temp;
		string name;
		int group;
		double GPA;

		for (int i = 0; i < count_students; i++)
		{
			cout << "Введите ФИО: ";
			getline(cin, name);
			cout << "Группу: ";
			cin >> group;
			cout << "Срений балл: ";
			cin >> GPA;
			cout << endl;
			temp.AddStudent(name, group, GPA);
			vs.push_back(temp);
			cin.clear();
			rewind(stdin);
		}
	}
	
	try
	{
		int n;
		cout << "Выберите файл для работы:\n" << "1) Текстовый в текстовом\n" << "2) Текстовый в бинарном\n" << "3) Бинарный в бинарном\n" << "0) Выход\n";
		cin >> n;
		switch (n)
		{
		case 1:
		{
			work_with_txtintxt(vs, path_txtintxt.c_str());
			break;
		}
		case 2:
		{
			work_with_txtinbin(vs, path_txtinbin.c_str());
			break;
		}
		case 3:
		{
			work_with_bininbin(vs, path_bin.c_str());
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			throw exception("Неправильный выбор файла\n");
		}
		}
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}

ostream& operator<<(ostream& os, const Student& st)
{
	os << st.name << '\0' << st.GroupNumber << ' ' << st.GPA << '\n';
	return os;
}

istream& operator>>(istream& is, Student& st)
{
	getline(is, st.name, '\0');
	is >> st.GroupNumber >> st.GPA;
	is.get();
	return is;
}

void write_binary(vector<Student>& vs, const char* file_name, bool isBin)
{
	ofstream fout;
	if (vs.size() != 0)
	{
		if (isBin)
			fout.open(file_name, ofstream::trunc | ofstream::binary);
		else
			fout.open(file_name, ofstream::trunc);

		if (fout.is_open())
		{
			for (int i = 0; i < vs.size(); i++)
			{
				fout << vs[i].name << '\0';
				fout.write(reinterpret_cast<char*>(&vs[i].GPA), sizeof(double));
				fout.write(reinterpret_cast<char*>(&vs[i].GroupNumber), sizeof(int));
			}
		}
		fout.close();
	}
	
}

void read_binary(vector<Student>& vs, const char* file_name, bool isBin)
{
	ifstream fin;
	Student st;
	if (isBin)
		fin.open(file_name, ios::binary);
	else
		fin.open(file_name);
	while (getline(fin, st.name, '\0'))
	{
		if (fin.eof())
			break;
		fin.read(reinterpret_cast<char*>(&st.GPA), sizeof(double));
		fin.read(reinterpret_cast<char*>(&st.GroupNumber), sizeof(int));
		vs.push_back(st);
	}
	fin.close();
}


vector<Student> del_name(vector<Student> vs, string name)
{
	vector<Student> ms;
	for (auto value : vs)
	{
		if (value.Get_name() != name)
			ms.push_back(value);
		else
			cout << "Запись удалена\n";
	}
	return ms;
}

void search_name(vector<Student> vs, string name)
{
	bool flag = false;
	for (auto value : vs)
		if (value.Get_name() == name)
		{
			value.GetInfo();
			flag = true;
		}
	if (!flag) cout << "Записи с таким условием не найдены!\n";
}

// функции текстового в текстовом
void write_txt(vector<Student>& vs, const char* path)
{
	if (vs.size() != 0)
	{
		ofstream fs;
		fs.open(path, ofstream::trunc);
		fs.close();

		fs.open(path);
		if (!fs.is_open())
			throw exception("File can't open\n");

		for (int i = 0; i < vs.size(); i++)
		{
			fs << vs[i];
		}
		fs.close();
	}
	
}

void read_txt(const char* path)
{
	fstream fs;
	fs.open(path, ios::in);
	if (!fs.is_open()) throw exception("File can't open\n");

	Student temp;
	while (fs >> temp)
		temp.GetInfo();

	fs.close();
}

void read_symbols_revers(const char* path)
{
	fstream fs;
	vector<int> indexs;
	Student temp;
	fs.open(path, ios::in);
	if (!fs.is_open()) throw exception("File can't open\n");

	char c;
	indexs.push_back(0);
	while (!fs.eof())
	{
		fs.get(c);
		if (c == '\n') indexs.push_back(fs.tellg());
	}
	indexs.pop_back();
	fs.clear();
	for (int i = indexs.size() - 2; i >= 0; i--)
	{
		fs.seekg(indexs[i]);
		fs >> temp;
		temp.GetInfo();
	}

	fs.close();
}

void search_name(string name, const char* path)
{
	fstream fs;
	fs.open(path, ios::in);
	if (!fs.is_open()) throw exception("File can't open\n");

	bool flag = false;
	Student temp;
	while (fs >> temp)
		if (temp.Get_name() == name)
		{
			temp.GetInfo();
			flag = true;
		}
	if (!flag) cout << "Записи с таким условием не найдены!\n";


	fs.close();
}

void del_name_and_write(string name, const char* path)
{
	fstream fs;
	Student temp;
	vector<Student> vs;
	fs.open(path, ios::in);
	if (!fs.is_open()) throw exception("File can't open\n");

	
	while (fs >> temp)
	{
		if (temp.Get_name() == name)
		{
			temp.GetInfo();
			cout << "Запись удалена\n";
		}
		else
			vs.push_back(temp);
	}
	fs.close();

	fs.open(path, ios::out | ios::trunc);
	if (!fs.is_open()) throw exception("File can't open\n");
	for (int i = 0; i < vs.size(); i++)
	{
		fs << vs[i];
	}

	fs.close();
}





