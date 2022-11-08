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

	cout << "��������� ��������: " << a.GetNum() << endl;
	
	a.operator=(b);
	cout << "����������: " << a.GetNum() << endl;
	
	a.operator[](3); // #1
	a[3][4][5];      // #2
	cout << "����������: " << a.GetNum() << endl;
	
	a(4);
	cout << "�������������: " << a.GetNum() << endl;

	a++;
	++a;
	cout << "������� ��������������: " << a.GetNum() << endl;

	INT c = a + b;
	cout << "�������� ��������������: " << c.GetNum() << endl;

	cout << "��������� a � �: " << (a == c) << endl;
	cout << "��������� a � a: " << (a == a) << endl << endl;


	cout << "������������� �������-���������" << endl;
	--a;
	a--;
	cout << "������� ��������������: " << a.GetNum() << endl;

	c = b - a;
	cout << "�������� ��������������: " << c.GetNum() << endl;

	cout << "��������� a � � (<): " << (a < c) << endl;
	cout << "��������� a � c (>): " << (a > a) << endl << endl;

	cout << "����� � �����" << endl;
	cout << a << endl << endl;

	cout << "������� ��������������" << endl;
	int value;
	value = int(a);
	cout << "�� ���������� ��� " << value << endl;

	INT seconds(1234);
	Clock clock = (Clock)seconds;
	cout << "� ���������������� ��� ";
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
