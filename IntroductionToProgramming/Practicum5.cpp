
#include <iostream>
using namespace std;

void Swap(int& a, int& b) {
	int conteiner = a;
	a = b;
	b = conteiner;
}

void Swap(double& a, double& b) {
	int conteiner = a;
	a = b;
	b = conteiner;
}

int nod(int n, int k) {
	if (n < k)
	{
		Swap(n, k);
	}

	while (k != 0)
	{
		int mod = n % k;
		n = k;
		k = mod;
	}

	return n;
}

void drob(int& a, int& b)
{
	int n = nod(a, b);

	a /= n;
	b /= n;
}

int nok(int a, int b)
{
	int n = nod(a, b);

	return (a * b) / n;
}

void sumDrob(int a, int b, int c, int d, int& ch, int& zn)
{
	int n = nok(d, b);

	a *= (n / b);
	c *= (n / d);

	ch = a + c;
	zn = n;

	int nodValue = nod(ch, zn);

	ch = ch / nodValue;
	zn = zn / nodValue;
}

//void sortNumbers(int& min, int& mid, int& max)//not done

int digitAtPositionK(int number, int k)
{
	int result = 0;
	if (k < 1)
	{
		cout << "Incorrect input!";
	}

	int i = 1;
	while (number > 0)
	{
		if (i == k)
		{
			number /= 10;
			continue;
		}

		result = (number % 10) + (result * 10);
		number /= 10;
	}
}

void DivideIntoTwoNumbersWithEvenDigitsAndOddDigits(int number, int& even, int& odd)
{
	while (number > 0)
	{
		int digit = number % 10;
		number /= 10;

		if (digit % 2 == 0)
		{
			even = even * 10 + digit;
		}
		else
		{
			odd += odd * 10 + digit;
		}
	}
}

int Substract(int from, int to, int number) 
{

}


int main()
{
	//swap
	/*int a, b;

	cin >> a >> b;
	Swap(a, b);
	cout << a << ' ' << b;*/

	//sum drob
	/*int a, b;
	cin >> a >> b;

	int c, d;
	cin >> c >> d;

	int ch, zn;

	sumDrob(a, b, c, d, ch, zn);

	cout << ch << ' ' << zn;*/
}