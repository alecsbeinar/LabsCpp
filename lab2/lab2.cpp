#include <iostream>
using namespace std;

class Clock
{
public:
	int hours;
	int minutes;
	int seconds;
	Clock(int h, int m, int s) : hours(h), minutes(m), seconds(s)
	{
	}
	void display()
	{
		cout << hours << ":" << minutes << ":" << seconds << std::endl;
	}
};

class INT
{
public:
	INT() { num = 0; }
	INT(int num) { this->num = num; }
	~INT() {}
	INT(const INT& other) { this->num = other.num; }

	int GetNum() { return num; }

	INT& operator = (const INT&);
	INT& operator [] (const int);
	INT& operator () (const int);
	INT& operator ++ ();
	INT& operator ++ (int);
	INT& operator + (const INT&);
	bool operator == (const INT&);

	friend INT& operator -- (INT&);
	friend INT& operator -- (INT&, int);
	friend INT& operator - (INT&,  const INT&);
	friend bool operator > (INT&, const INT&);
	friend bool operator < (INT&, const INT&);
	friend ostream& operator << (ostream&, const INT&);

	operator int() const
	{
		return num;
	}

	explicit operator Clock() const
	{
		int h = num / 3600;
		int m = (num - h * 3600) / 60;
		int s = num - h * 3600 - m * 60;
		return Clock(h, m, s);
	}

private:
	int num;
};




int main()
{
	setlocale(LC_ALL, "Rus");
	INT a;
	INT b(4);

	cout << "Начальное значение: " << a.GetNum() << endl;
	
	a.operator=(b);
	cout << "Присвоение: " << a.GetNum() << endl;
	
	a.operator[](3); // #1
	a[3][4][5];      // #2
	cout << "Индексация: " << a.GetNum() << endl;
	
	a(4);
	cout << "Инициализация: " << a.GetNum() << endl;

	a++;
	++a;
	cout << "Унарные арифметические: " << a.GetNum() << endl;

	INT c = a + b;
	cout << "Бинарные арифметические: " << c.GetNum() << endl;

	cout << "Сравнения a и с: " << (a == c) << endl;
	cout << "Сравнения a и a: " << (a == a) << endl << endl;


	cout << "Дружественные функции-операторы" << endl;
	--a;
	a--;
	cout << "Унарные арифметические: " << a.GetNum() << endl;

	c = b - a;
	cout << "Бинарные арифметические: " << c.GetNum() << endl;

	cout << "Сравнения a и с (<): " << (a < c) << endl;
	cout << "Сравнения a и c (>): " << (a > a) << endl << endl;

	cout << "Вывод в поток" << endl;
	cout << a << endl << endl;

	cout << "Функции преобразования" << endl;
	int value;
	value = int(a);
	cout << "Во встроенный тип " << value << endl;

	INT seconds(1234);
	Clock clock = (Clock)seconds;
	cout << "В пользовательский тип ";
	clock.display();
	cout << endl;
}



INT& INT::operator=(const INT& other)
{
	this->num = other.num;
	return *this;
}

INT& INT::operator[](const int index) { this->num -= index; return *this; }

INT& INT::operator()(const int index) { this->num += index; return *this; }

INT& INT::operator++()
{
	this->num++;
	return *this;
}
INT& INT::operator++(int trash)
{
	INT temp(*this);
	this->num++;
	return temp;
}

INT& INT::operator+(const INT& other)
{
	INT temp;
	temp.num = this->num + other.num;
	return temp;
}

bool INT::operator==(const INT& other)
{
	return this->num == other.num;
}



INT& operator--(INT& value)
{
	value.num--;
	return value;
}

INT& operator--(INT& value, int trash)
{
	INT temp(value);
	value.num--;
	return temp;
}
INT& operator-(INT& value, const INT& other)
{
	INT temp;
	temp.num = value.num - other.num;
	return temp;
}

bool operator>(INT& value, const INT& other)
{
	return value.num > other.num;
}

bool operator<(INT& value, const INT& other)
{
	return value.num < other.num;
}

ostream& operator<<(ostream& os, const INT& value)
{
	os << value.num;
	return os;
}
