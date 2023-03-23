#include <iostream>
#include <iterator>
#include <cstddef>
#include <string>
using namespace std;

template<typename T>
class Node
{
public:
	T GetValue() { return value; }

	Node(T value = T())
	{
		prev = nullptr;
		this->value = value;
	}

	template<class T> friend class Stack;

private:
	Node* prev;
	T value;
};



template<typename T>
class Stack
{
public:
	Stack(bool unique = false);
	~Stack();

	T& Getsize() { return size; }

	void push(T data);
	T pop();
	int find(T data);
	T& operator[](const int index);
	void clear();
	void insert(T data, const int index);
	void removeAt(const int index);


	struct Iterator
	{
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = Node<T>;
		using pointer = Node<T>*;
		using reference = Node<T>&;

		Iterator(pointer ptr) : m_ptr(ptr) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() { return m_ptr; }

		// Prefix increment
		Iterator& operator++() { m_ptr = m_ptr->prev; return *this; }

		// Postfix increment
		Iterator operator++(int) { Iterator tmp = *this; m_ptr = m_ptr->prev; return tmp; }

		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

	private:
		pointer m_ptr;
	};

	Iterator begin() { return Iterator(top); }
	Iterator end() { return Iterator(nullptr); }

	void Print()
	{
		for (auto i : *this)
			cout << i.value << " ";
		cout << endl;
	}

private:
	Node<T>* top;
	int size;
	bool unique;
};

template <typename T>
void Menu()
{
	cout << "Unique or multi? (u/m)\n";
	char c;
	cin >> c;
	bool flag = c == 'u';
	Stack<T> st = *(new Stack<T>(flag));
	try
	{
		flag = true;
		T temp;
		int index;
		while (flag)
		{
			rewind(stdin);
			cin.clear();
			cout << "1. push\n" << "2. insert\n" << "3. pop\n" << "4. removeAt\n" << "5. find\n" << "6. clear\n" << "7. print\n" << "8 - quite\n";
			int choice;
			cin >> choice;
			system("CLS");
			switch (choice)
			{
			case(1):
			{
				cout << "Input data\n";
				cin >> temp;
				st.push(temp);
				break;
			}
			case(2):
			{
				cout << "Input index\n";
				cin >> index;
				cout << "Input data\n";
				cin >> temp;
				st.insert(temp, index);
				break;
			}
			case(3):
			{
				cout << "Pop return: " << st.pop() << endl;
				break;
			}
			case(4):
			{
				cout << "Input index\n";
				cin >> index;
				st.removeAt(index);
				cout << "RemoveAt complete!" << endl;
				break;
			}
			case(5):
			{
				cout << "Input data\n";
				cin >> temp;
				cout << "Find return index: " << st.find(temp) << endl;
				break;
			}
			case(6):
			{
				cout << "CLEAR ALL!" << endl;
				st.clear();
				break;
			}
			case(7):
			{
				cout << "Print using iterator\n";
				st.Print();
				break;
			}
			case(8):
			{
				flag = false;
				break;
			}
			default:
				break;
			}
		}
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "1) int\n" << "2) double\n" << "3) string\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case(1):
	{
		Menu<int>();
		break;
	}
	case(2):
	{
		Menu<double>();
		break;
	}
	case(3):
	{
		Menu<string>();
		break;
	}
	default:
		break;
	}
}

template<typename T>
Stack<T>::Stack(bool unique)
{
	size = 0;
	top = nullptr;
	this->unique = unique;
}

template<typename T>
Stack<T>::~Stack()
{
	clear();
}

template<typename T>
void Stack<T>::push(T data)
{
	if (!unique || (unique && find(data) == -1))
	{
		Node<T>* node = new Node<T>(data);
		if (top == nullptr)
		{
			top = node;
			node->prev = nullptr;
		}
		else
		{
			node->prev = top;
			top = node;
		}
		size++;
	}
	else
		throw exception("Not unique value\n");

}

template<typename T>
T Stack<T>::pop()
{
	Node<T>* temp_top = top;
	T temp = top->value;

	top = top->prev;
	delete temp_top;
	size--;
	return temp;
}

template<typename T>
int Stack<T>::find(T data)
{
	Node<T>* temp = this->top;
	for (int i = 0; i < size; i++)
	{
		if (temp->value == data)
			return i;
		temp = temp->prev;
	}
	return -1;
}

template<typename T>
T& Stack<T>::operator[](const int index)
{
	int  counter = 0;
	Node<T>* current = this->top;
	while (current != nullptr)
	{
		if (counter == index)
			return current->value;
		current = current->prev;
		counter++;
	}
}

template<typename T>
void Stack<T>::clear()
{
	while (size)
	{
		pop();
	}
}

template<typename T>
void Stack<T>::insert(T data, const int index)
{
	if (!unique || (unique && find(data) == -1))
	{
		if (index == 0)
		{
			push(data);
		}
		else
		{
			Node<T>* temp = new Node<T>(data);
			Node<T>* iterator = this->top;
			for (int i = 0; i < index - 1 && iterator->prev != nullptr; i++)
				iterator = iterator->prev;

			temp->prev = iterator->prev;
			iterator->prev = temp;

			size++;
		}
	}
	else
		throw exception("Not unique value\n");
}

template<typename T>
void Stack<T>::removeAt(const int index)
{
	if (index < size)
	{
		if (index == 0)
			pop();
		else
		{
			Node<T>* todelete = this->top;
			Node<T>* iterator = this->top;
			for (int i = 0; i < index; i++)
			{
				iterator = todelete;
				todelete = todelete->prev;
			}

			iterator->prev = todelete->prev;
			delete todelete;

			size--;
		}
	}
	else
		throw exception("Index out of range");
}
