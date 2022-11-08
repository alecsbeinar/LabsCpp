#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Human
{
public:
	Human()
	{
		cout << "Вызван конструктор HUMAN1" << endl;
		name = "Ivanov Ivan";
	}
	Human(string name) : Human() { cout << "Вызван конструктор HUMAN2" << endl; this->name = name; }
	virtual ~Human() { cout << "Вызван деструктор HUMAN" << endl; }

	virtual void display() = 0;
	virtual void calcult() = 0;

protected:
	string name;
};

class Employee : public Human
{
public:
	Employee() : Human()
	{
		cout << "Вызван конструктор EMPLOYEE" << endl;
		salary = 0;
	}
	Employee(double salary, string name) : Human(name)
	{
		cout << "Вызван конструктор EMPLOYEE" << endl;
		this->salary = salary;
	}
	~Employee() { cout << "Вызван деструктор EMPLOYEE" << endl; }

	void display() override
	{
		cout << "Name: " << name << endl;
		cout << "Salary: " << salary << endl;
	}

	void calcult() override
	{
		cout << salary - salary * 0.18 << endl;
	}

private:
	double salary;
};

class Employer : public Employee
{
public:
	Employer() : Employee()
	{
		cout << "Вызван конструктор EMPLOYER" << endl;
		company = "NoName";
	}
	Employer(string company, double salary, string name) : Employee(salary, name)
	{
		cout << "Вызван конструктор EMPLOYER" << endl;
		this->company = company;
	}
	~Employer() { cout << "Вызван деструктор EMPLOYER" << endl; }

	void display()
	{
		Employee::display();
		cout << "Company: " << company << endl;
	}

	

private:
	string company;
};


class Student : public Human
{
public:
	Student() : Human() { cout << "Вызван конструктор STUDENT" << endl; group = 000000; }
	Student(int group, string name) : Human(name) { cout << "Вызван конструктор STUDENT" << endl; this->group = group; }
	~Student() { cout << "Вызван деструктор STUDENT" << endl; }

	void display() override
	{
		cout << "Name: " << name << endl;
		cout << "Group: " << group << endl;
	}

	void calcult() override
	{
		cout << name[0] - 'A' << endl;
	}

private:
	int group;
};






int main()
{
	setlocale(LC_ALL, "Rus");
	Human** humans = new Human* [3];
	humans[0] = new Employee(1000.1, "EE1");
	humans[1] = new Employer("Comp", 999, "ER1");
	humans[2] = new Student(150505, "Alecsandr");

	for (int i = 0; i < 3; i++)
	{
		humans[i]->display();
		cout << endl << "Calculation: " << endl;
		humans[i]->calcult();
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		delete humans[i];
	}
	delete humans;

}



