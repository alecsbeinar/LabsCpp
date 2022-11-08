#include <iostream>
using namespace std;

class Human
{
public:
	Human()
	{
		cout << "Вызван конструктор HUMAN" << endl;
		height = 170;
		weight = 62;
		age = 50;
		gender = "man";
		name = "Ivanov Ivan";
	}
	/*Human(string name) { this->name = name; }
	Human(string name, string gender) : Human(name) 
	{ this->gender = gender; }
	Human(string name, string gender, int age) : Human(name, gender) 
	{ this->age = age; }
	Human(string name, string gender, int age, double weight) : Human(name, gender, age) 
	{ this->weight = weight; }*/
	Human(string name, string gender, int age, double weight, double height)  
	{
		this->name = name;
		this->gender = gender;
		this->age = age;
		this->weight = weight;
		this->height = height; 
	}
	~Human() {}

	void display()
	{
		cout << "Name: " << name << endl << "Gender: " << gender << endl << "Age: " << age << endl << "Height: " << height << endl << "Weight: " << weight << endl;
	}

protected:
	double height;
	double weight;
	int age;
	string gender;
	string name;

};

class Employee : virtual public Human
{
public:
	Employee() : Human()
	{
		cout << "Вызван конструктор EMPLOYEE" << endl;
		salary = 0;
	}
	Employee(double salary, string _name, string _gender, int _age, double _height, double _weight)
	{
		this->salary = salary;
		name = _name;
		gender = _gender;
		age = _age;
		height = _height;
		weight = _weight;
	}
	~Employee() {}

	void display()
	{
		Human::display();
		cout << "Salary: " << salary << endl;
	}

protected:
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
	Employer(string company, double salary, string name, string gender, int age, double height, double weight) : Employee(salary, name, gender, age, weight, height)
	{
		this->company = company;
	}
	~Employer() {}

	void display()
	{
		Employee::display();
		cout << "Company: " << company << endl;
	}

protected:
	string company;
};


class Student : virtual public Human
{
public:
	Student() : Human() { cout << "Вызван конструктор STUDENT" << endl; group = 000000; }
	Student(int group, string _name, string _gender, int _age, double _height, double _weight)  
	{
		name = _name;
		gender = _gender;
		age = _age;
		height = _height;
		weight = _weight;
		this->group = group; 
	}
	~Student() {}

	void display()
	{
		Human::display();
		cout << "Group: " << group << endl;
	}
protected:
	int group;
};

class Trainee : public Student
{
public:
	Trainee() : Student() { cout << "Вызван конструктор Trainee" << endl; countDays = 0; }
	Trainee(int countDays, int group, string name, string gender, int age, double height, double weight) : Student(group, name, gender, age, height, weight) { this->countDays = countDays; }
	~Trainee() {}

	void display()
	{
		Student::display();
		cout << "Count days: " << countDays << endl;
	}
protected:
	int countDays;
};


class EmpTrainee: public Trainee, public Employer
{
public:
	EmpTrainee() { commercialExpirience = 0; }
	EmpTrainee(double commercialExpirience, int countDays, int group, string name, string gender, int age, double height, double weight, double salary, string company) : Trainee(countDays, group, name, gender, age, height, weight), Employer(company, salary, name, gender, age, height, weight) { this->commercialExpirience = commercialExpirience; }
	void display()
	{
		cout << "display EmpTrainee" << endl;
		Trainee::display();
		cout << company << endl;
		cout << salary << endl;
	}
private:
	double commercialExpirience;
};




int main()
{
	setlocale(LC_ALL, "Rus");
	
	
	Trainee t(20, 150505, "Alecsandr", "man", 18, 192, 82);
	t.display();
	cout << endl;
	EmpTrainee h;
	h.display();

}



