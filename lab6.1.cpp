#include <iostream>
#include <iostream>
#include <windows.h>
using namespace std;

void function(int x,int y,int z)
{
	cout << "|    "; if (x) cout << "T"; else cout << "F";
	cout << "     |    "; if (y) cout << "T"; else cout << "F";
	cout << "     |    "; if (z) cout << "T"; else cout << "F";
	cout << "     |     "; if (y && z) cout << "T"; else cout << "F";
	cout << "      |        "; if (x && (y && z)) cout << "T"; else cout << "F";
	cout << "        |         "; if (!(x && (y && z))) cout << "T"; else cout << "F";
	cout << "        |        "; if (x || (y || z)) cout << "T"; else cout << "F";
	cout << "        |             "; if (!(x && (y && z)) || (x || (y || z))) cout << "T"; else cout << "F";
	cout << "                 |" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int x, y, z, a;
	Start:
	cout << "Напишіть 0, аби перейти до ручного введення" << endl;
	cout << "Напишіть 1, аби перейти до автоматичного знаходження істинності значень" << endl;
	cin >> a;
	switch (a)
	{
	case 0:
	Repeat:
		cout << "Введіть x(1 - True, 0 - False): "; cin >> x;
		if (x == 0 || x == 1)
			goto Next1;
		else
		{
			cout << "Ви ввели некоректне значення, повторіть спробу" << endl;
			goto Repeat;
		}
		Next1:
		cout << "Введіть y(1 - True, 0 - False): "; cin >> y;
		if (y == 0 || y == 1)
			goto Next2;
		else
		{
			cout << "Ви ввели некоректне значення, повторіть спробу" << endl;
			goto Next1;
		}
		Next2:
		cout << "Введіть z(1 - True, 0 - False): "; cin >> z;
		if (z == 0 || z == 1)
			goto Next3;
		else
		{
			cout << "Ви ввели некоректне значення, повторіть спробу" << endl;
			goto Next2;
		}
	Next3:
		cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|    x     |    y     |    z     |   (y&&z)   |   (x&&(y&&z))   |   !(x&&(y&&z))   |   (x||(y||z))   |   !(x&&(y&&z))||(x||(y||z))   |" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
		function(x, y, z);
		Again:
		cout << "Перевірити ще раз? (Введіть 0 щоб запустити ще раз, 1 щоб вийти): "; cin >> a;
		if (a == 0)
			goto Repeat;
		else
			if (a == 1)
				goto Start;
			else
			{
				cout << "Ви ввели некоректне значення, повторіть спробу" << endl;
				goto Again;
			}
		case 1: 
			cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "|    x     |    y     |    z     |   (y&&z)   |   (x&&(y&&z))   |   !(x&&(y&&z))   |   (x||(y||z))   |   !(x&&(y&&z))||(x||(y||z))   |" << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
			x = 1; y = 1; z = 1; function(x, y, z);
			x = 1; y = 1; z = 0; function(x, y, z);
			x = 1; y = 0; z = 0; function(x, y, z);
			x = 0; y = 0; z = 0; function(x, y, z);
			x = 0; y = 0; z = 1; function(x, y, z);
			x = 0; y = 1; z = 1; function(x, y, z);
			x = 1; y = 0; z = 1; function(x, y, z);
			x = 0; y = 1; z = 0; function(x, y, z);
			goto Start;
	}
}