
#include <iostream>

using namespace std;

void print(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << "   ";
	}
}

void Swap(int& a, int& b) {
	int conteiner = a;
	a = b;
	b = conteiner;
}

double averageSumOfArrElements(const int arr[], size_t size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum / size;
}

bool isSortedArrAsc(const int arr[], size_t size)
{
	for (int i = 0; i < size - 1; i += 2)
	{
		if (arr[i] < arr[i + 1])
		{
			return false;
		}
	}

	return true;
}

void minAndMaxElementsInArr(const int arr[], size_t size, int& min, int& max)
{
	min = INT16_MAX;
	max = INT16_MIN;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}

		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
}

void removeAt(int arr[], size_t size, int index)
{
	arr[index] = 0;

	for (int i = index; i < size - 1; i++)
	{
		Swap(arr[i], arr[i + 1]);
	}
}

bool isPalindromArr(const int arr[], size_t size)
{
	for (int i = 0; i < size / 2; i++)
	{
		if (arr[i] != arr[size - i - 1])
		{
			return false;
		}
	}

	return true;
}

void Reverse(int arr[], size_t size)
{
	for (size_t i = 0; i < size / 2; i++)
	{
		Swap(arr[i], arr[size - i - 1]);
	}
}

void removeNegativeNumbers(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			removeAt(arr, size, i);
		}
	}
}

void addOneToNumberInArr(int arr[])
{
	int num = 1;

	for (int i = 0; i < 5; i++)
	{
		num += num * 10 + arr[i];
	}

	num++;

	for (int i = 4; i > 0; i++)
	{
		arr[i] = num % 10;
		num / 10;
	}
}

bool conatinDigit(int num, int digit)
{
	if (num == 0 && digit == 0)
	{
		return true;
	}

	while (num != 0)
	{
		if (num % 10 == digit)
		{
			return true;
		}

		num /= 10;
	}

	return false;
}

void makeAllNumbersToZeroIfTheyDontContainTheirIndexNumber(int arr[])
{
	for (size_t i = 0; i < 10; i++)
	{
		if (!conatinDigit(arr[i], i))
		{
			arr[i] == 0;
		}
	}
}

void countOcuurencesOfNumbersBetween0And19(const int arr[], int occurences[], size_t size)
{
	for (int i = 0; i < size-1; i++)
	{
		occurences[arr[i]]++;
	}
}

int missingNumberInPermutation(const int arr[], int occurences[])
{
	countOcuurencesOfNumbersBetween0And19(arr, occurences, 21);

	for (size_t i = 0; i < 21; i++)
	{
		if (occurences[i] == 0)
		{
			return i;
		}
	}

	return -1;
}

void UnionAndIntersectionOfTwoArrays(int arr1[], size_t size1, const int arr2[], size_t size2, int result[])
{
	int ocuurencesArr1 = 
}



int main()
{
	/*int arr[] = { 1, 5, 7, -8 , 4, -11, 0, -9 };

	removeNegativeNumbers(arr, 8);
	print(arr, 8);*/

	/*int arr[] = { 0, 2, 1, 4, 6, 5, 8, 7, 10, 9, 12, 11, 14, 13, 16, 15, 18, 17, 20, 19 };
	int ocurrences[21] = { 0 };

	cout << missingNumberInPermutation(arr, ocurrences);*/


}