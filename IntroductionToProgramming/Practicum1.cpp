
#include <iostream>
using namespace std;

int main()
{

	//zad 1
	//mine
	int input = 0;

	cin >> input;
	cout << (input % 2 == 0 ? 0 : 1);

	//theirs
	int n;
	cin >> n;
	bool isEven = (n % 2 == 0);
	cout << isEven;

}