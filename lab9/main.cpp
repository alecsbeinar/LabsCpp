#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <Windows.h>
#include "Human.h"
#include "Worker.h"
#include "Boss.h"
#include "Department.h"
using namespace std;

//class c1
//{
//public:
//	c2* obj;
//	c1()
//	{
//		obj = new c2();
//	};
//
//	~c1()
//	{
//		delete obj;
//	}
//};
//
//class c2 {
//private:
//	c2() {};
//	friend c1;
//};

template <typename T>
void PrintMs(T ms)
{
	cout << endl << endl << setfill('-') << setw(40) << ' ' << endl;
	cout << "Выберите:\n";
	for (int i = 0; i < ms.size(); i++)
	{
		cout << i << ") " << ms[i]->GetName() << endl;
	}
	cout << setfill('-') << setw(40) << ' ' << endl << endl;
}

template<typename T>
void FillMs(vector<T*>& ms, int count)
{
	std::string temp;
	for (int i = 0; i < count; i++)
	{
		rewind(stdin);
		cin.clear();
		cin >> temp;
		ms.push_back(new T(temp));
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int count;
	std::string temp;

	cout << "Введите количество специальностей: ";
	cin >> count;
	vector<MYns::Speciality*> specialitys;
	FillMs<MYns::Speciality>(specialitys, count);

	cout << "Введите количество рабочих мест: ";
	cin >> count;
	vector<MYns::Workplace*> workplaces;
	FillMs<MYns::Workplace>(workplaces, count);

	cout << "Введите количество должностей: ";
	cin >> count;
	vector<MYns::Position*> positions;
	FillMs<MYns::Position>(positions, count);

	cout << "Введите количество работников: ";
	cin >> count;
	vector<MYns::Worker*> workers;

	double salary;
	std::string name;
	int age;
	int choice1, choice2, choice3;
	for (int i = 0; i < count; i++)
	{
		cout << "Имя: ";
		cin >> name;
		cout << "Возраст: ";
		cin >> age;
		cout << "Зарплата: ";
		cin >> salary;
		PrintMs(specialitys);
		cin >> choice1;
		PrintMs(workplaces);
		cin >> choice2;
		PrintMs(positions);
		cin >> choice3;
		MYns::Worker* worker = new MYns::Worker(salary, name, age, specialitys[choice1], positions[choice3], workplaces[choice2]);
		workers.push_back(worker);
	}

	MYns::Boss b("mycompany", workers[0]);
	cout << endl << "Босс:" << endl;
	b.ShowInfo();
	MYns::Department dep(workers);
	for (auto worker : dep.GetWorkers())
	{
		cout << endl;
		worker->ShowInfo();
		cout << endl;
	}
}