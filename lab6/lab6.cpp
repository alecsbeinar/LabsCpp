#include <iostream>
#include <string>
using namespace std;

class MyException : public exception
{
public:
	MyException(const char* msg, string value) : exception(msg)
	{
		this->value = value;
	}

	string GetValueState()
	{
		return value;
	}

private:
	string value;
};


template <typename T>
class Array
{
public:
	Array(int len)
	{
		if (len == 0) throw "Передана нулевая длина";
		ms = new T[len];
		this->len = len;
		for (int i = 0; i < len; i++)
		{
			cin >> ms[i];
			if (cin.fail())
			{
				throw MyException("Введен не тот тип данных", typeid(ms[i]).name());
			}
			rewind (stdin);
		}
	}
	~Array()
	{
		delete[] ms;
	}
	Array(const Array& other)
	{
		this->len = other.len;
		if (ms) delete[] ms;
		ms = new T[len];
		for (int i = 0; i < len; i++) ms[i] = other[i];
		return *this;
	}

	void push_back(T el)
	{
		T* n_ms = new T[len + 1];
		for (int i = 0; i < len; i++) n_ms[i] = ms[i];
		n_ms[len] = el;

		delete[] ms;
		ms = n_ms;
		this->len = len + 1;
	}
	T pop()
	{
		T* n_ms = new T[len - 1];
		for (int i = 0; i < len - 1; i++) n_ms[i] = ms[i];
		T temp = ms[len - 1];

		delete[] ms;
		ms = n_ms;
		this->len = len - 1;
		return temp;
	}
	void print()
	{
		for (int i = 0; i < len; i++) cout << ms[i] << " ";
		cout << endl;
	}
	T search(T el) throw(const char*)
	{
		for (int i = 0; i < len; i++)
				if (ms[i] == el)
					return i;
			throw 1;
	}

	Array& operator = (const Array& other)
	{
		this->len = other.len;
		if (ms) delete[] ms;
		ms = new T[len];
		for (int i = 0; i < len; i++) ms[i] = other.ms[i];
		return *this;
	}
	bool operator == (const Array& other)
	{
		if (len == other.len)
		{
			for (int i = 0; i < len; i++)
				if (ms[i] != other.ms[i])
					return false;
			return true;
		}
		return false;
	}


private:
	T* ms;
	int len;
};

void my_term()
{
	cout << "Собственная функция-обработчик" << endl;

	exit(1);
}

void my_unexpected()
{
	cout << "Собственный неожиданный обработчик" << endl;
}

template <typename T>
void f(T i) throw(const char*)
{
	throw 1;
}

int main()
{
	setlocale(LC_ALL, "rus");
	set_terminate(my_term);
	set_unexpected(my_unexpected);
	try
	{
		Array<int> a1(1);
		Array<int> a2(3);
		a1.print();
		a2.print();
		a1.operator=(a2);
		a1.print();
		a2.print();
		cout << (a1 == a2) << endl;
		a1.push_back(5);
		//cout << "Функция pop" << a1.pop() << endl;
		cout << a1.search(2) << endl; // нет обработчика такого типа
		f(1); // выкидывает икслючение тип которого не прописан
	}
	catch (const char* st)
	{
		cout << st << endl;
	}
	catch (MyException& ex)
	{
		cout << ex.what() << endl;
		cout << "Должен быть " << ex.GetValueState() << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}


//
//#include <iostream>
//using namespace std;
//
//struct E {
//    const char* message;
//    E(const char* arg) : message(arg) { }
//};
//
//void my_unexpected() {
//    cout << "Call to my_unexpected" << endl;
//    throw E("Exception thrown from my_unexpected");
//}
//
//void f() throw(E) {
//    cout << "In function f(), throw const char* object" << endl;
//    throw("Exception, type const char*, thrown from f()");
//}
//
//int main() {
//    set_unexpected(my_unexpected);
//    try {
//        f();
//    }
//    catch (E& e) {
//        cout << "Exception in main(): " << e.message << endl;
//    }
//}