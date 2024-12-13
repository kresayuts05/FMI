#include <iostream>

unsigned myStrlen(const char* str)
{
	if (!str)
		return 0;

	unsigned result = 0;
	while (*str) //is the same as (*str) != '\0'
	{
		result++;
		str++;
	}
	return result;
}

//copy the source to destination.
//We assume that in dest the are enough cells.
void myStrcpy(const char* source, char* dest)
{
	if (!source || !dest)
		return;
	while (*source)
	{
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
}

// - first < second
// 0 first == second
// + first > second
int myStrcmp(const char* first, const char* second)
{
	if (!first || !second)
		return 0; //some error value

	//we skip the common prefix, but not the terminating zero!
	while ((*first) && (*second) && ((*first) == (*second))) //acutally the (*second) check can be missed here.
	{
		first++;
		second++;
	}

	return (*first - *second);

}


void myStrcat(char* first, const char* second)
{
	if (!first || !second)
		return;
	myStrcpy(second, first + myStrlen(first));
}

bool strEqualStr(const char* str, const char* str2)
{
	//why?
	while (*str && *str2)
	{
		if (!(*str == *str2))
		{
			return false;
		}

		str++;
		str2++;
	}

	return true;
}

//5x5
//pitaj angel
bool containStringInMatrix(char matrix[][5], char* str)
{
	if (!str || !matrix)
	{
		return false;
	}

	char currWord[6];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			currWord[j] = matrix[i][j];
		}
		*currWord += '\0';

		if (strEqualStr(currWord, str))
		{
			return true;
		}

		//ivan taka kaza za da vurne pointer-a v nachaloto
		// kresa ne e suglasna
		//str -= 5;  
	}

	return false;

}

bool isPalindrom(char* str)
{
	if (!str)
	{
		return false;
	}

	int strLen = myStrlen(str);

	char* front = str;
	char* end = str + strLen - 1;

	for (int i = 0; i < strLen / 2; i++)
	{
		if (*(front++) != *(end--))
		{
			return false;
		}
	}

	return true;
}

// 65 A
//97 a
void lowerToUpperAndUpperToLowerCaseOfLettersInStr(char* str)
{
	int strLen = myStrlen(str);

	while (*str)
	{
		// lower to upper
		if (*str >= 'A' && *str <= 'Z')
		{
			*str = *str - 'A' + 'a';
		}
		else
		{
			*str = (*str) - 'a' + 'A';
		}

		str++;
	}

	str -= strLen;

	std::cout << str;
}

int main()
{
	/*char matrix[5][5] = {
		 {'F', 'G', 'H', 'I', 'J'},
		 {'K', 'L', 'M', 'N', 'O'},
		 {'A', 'B', 'C', 'D', 'E'},
		 {'P', 'Q', 'R', 'S', 'T'},
		 {'U', 'V', 'W', 'X', 'Y'}
	};

	char str[] = { 'A', 'B', 'C', 'D', 'E', '\0' };

	std::cout << containStringInMatrix(matrix, str);*/


	char str[] = { 'A', 'B', 'C', 'D', 'A', '\0' };
	char str1[] = { 'A', 'B', 'C', 'B', 'A', '\0' };

	//std::cout << isPalindrom(str) << std::endl;
	//std::cout << isPalindrom(str1) << std::endl;

	lowerToUpperAndUpperToLowerCaseOfLettersInStr(str1);
}