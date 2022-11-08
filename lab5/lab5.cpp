#include <iostream>
#include <string>
using namespace std;

template<typename T>
T* SortMs(T* ms, int len)
{
	register int i, j, dp;
	T a;
	for (dp = len / 2; dp > 0; dp /= 2)
		for (i = dp; i < len; i++)
			for (j = i - dp; j >= 0 && ms[j] > ms[j + dp]; j -= dp)
			{
				a = ms[j];
				ms[j] = ms[j + dp];
				ms[j + dp] = a;
			}

	return ms;
}


template<typename T>
void out_ms(T* ms, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << ms[i] << " ";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int cel[] = { 1, 0, 0, 2 };
	int len_cel = sizeof(cel) / sizeof(*cel);

	double d[] = { 7.5, 9.89, 12.70, 1.13 };
	int len_d = sizeof(d) / sizeof(*d);

	char ch[] = { 'w', 'o', 'r', 'l', 'd' };
	int len_ch = sizeof(ch) / sizeof(*ch);

	string str[] = { "Apple", "Swift", "Home" };
	int len_str = sizeof(str) / sizeof(*str);

	out_ms(cel, len_cel);
	out_ms(d, len_d);
	out_ms(ch, len_ch);
	out_ms(str, len_str);

	cout << "\nSorted arrays:\n";
	out_ms(SortMs(cel, len_cel), len_cel);
	out_ms(SortMs(d, len_d), len_d);
	out_ms(SortMs(ch, len_ch), len_ch);
	out_ms(SortMs(str, len_str), len_str);
}