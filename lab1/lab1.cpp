#include <iostream>
#include <string>
#include <vector>
using namespace std;

static int ID = 0;

class Student
{
	int id;
	string name;
	int rate;

	friend class Dean;
	friend void PrintClass(Student);

	

public:
	void Setname(string str) { name = str; }
	void Setrate(int num) { rate = num; }
	int InicializationID() { return ID++; }

	int Getid() { return id; }
	string Getname() { return name; }
	int Getrate() { return rate; }

	Student()
	{
		id = 0;
		name = "Иванов Иван Иванович";
		rate = 0;
	}

	Student(string name, int rate)
	{
		this->id = InicializationID();
		this->name = name;
		this->rate = rate;
	}

	~Student() {}
};

class Dean
{
public:
	void SetStudentRate(Student& st)
	{
		cout << "Enter Student rate: " << endl;
		cin >> st.rate;
	}

	~Dean() {}
};

void PrintClass(Student st)
{
	cout << "Student ID: " << st.id << endl;
	cout << "Name of student: " << st.name << endl;
	cout << "Student rate: " << st.rate << endl;
}



int main()
{
	setlocale(LC_ALL, "rus");
	vector<Student> ms;
	Dean d;


	string name;
	int rate;
	string cont;
	cont = "Yes";
	while (cont == "Yes" or cont == "Y" or cont == "y" or cont == "yes")
	{
		cout << "Enter student name: ";
		cin >> name;
		cout << "Enter student rate: ";
		cin >> rate;
		ms.push_back(Student(name, rate));

		cout << "Want to continue?" << endl;
		cin >> cont;
	}


	Student st1("Sanek", 10);
	Student st2("San", 9);
	PrintClass(st1);
	PrintClass(st2);
	d.SetStudentRate(st1);
	d.SetStudentRate(st2);
	PrintClass(st1);
	PrintClass(st2);

	cout << endl << endl;

	for (int i = 0; i < ms.size(); i++)
	{
		PrintClass(ms[i]);
		d.SetStudentRate(ms[i]);
		PrintClass(ms[i]);
	}


}