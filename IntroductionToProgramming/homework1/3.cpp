#include <iostream>

// Взети от материалите на Ангел Димитриев семинар 4
// начало
unsigned getDigitsCount(unsigned n)
{
	if (n == 0)
	{
		return 1;
	}
	unsigned count = 0;

	while (n != 0)
	{
		count++;
		n /= 10;
	}

	return count;
}

unsigned countDigitOccurences(unsigned n, unsigned digit)
{
	if (digit == 0 && n == 0)
	{
		return 1;
	}

	unsigned count = 0;

	while (n != 0)
	{
		int lastDigit = n % 10;

		if (lastDigit == digit)
		{
			count++;
		}

		n /= 10;
	}

	return count;
}

bool areAllDistinctDigits(unsigned n)
{
	for (int i = 0; i <= 9; i++)
	{
		if (countDigitOccurences(n, i) > 1)
		{
			return false;
		}
	}

	return true;
}

bool isValidInput(unsigned n, unsigned digitsCount)
{
	return areAllDistinctDigits(n) && getDigitsCount(n) == digitsCount;
}

unsigned getBulls(unsigned toGuess, unsigned myGuess)
{
	unsigned bulls = 0;
	while (toGuess != 0)
	{
		if (toGuess % 10 == myGuess % 10)
			bulls++;
		toGuess /= 10;
		myGuess /= 10;
	}
	return bulls;

}

unsigned getBullsAndCowsSum(unsigned toGuess, unsigned myGuess)
{
	unsigned sum = 0;
	while (toGuess != 0)
	{
		int lastDigit = toGuess % 10;

		bool contains = countDigitOccurences(myGuess, lastDigit) == 1;

		if (contains)
			sum++;

		toGuess /= 10;
	}
	return sum;
}

void getBullsAndCows(unsigned toGuess, unsigned myGuess, unsigned& bulls, unsigned& cows)
{
	bulls = getBulls(toGuess, myGuess);
	cows = getBullsAndCowsSum(toGuess, myGuess) - bulls;
}

// край

void getAllNDigitNumbersWithDistinctDigits(int start, int end, int result[], int& count) {

	for (int i = start; i <= end; i++)
	{
		if (areAllDistinctDigits(i))
		{
			result[count++] = i;
		}
	}
}

void filterForNumber(int filter, int bulls, int cows, int arr[], bool arrBoolean[], int len)
{
	for (int i = 0; i < len; i++)
	{
		unsigned currBulls = 0;
		unsigned currCows = 0;
		getBullsAndCows(filter, arr[i], currBulls, currCows);

		if (currBulls != bulls || currCows != cows)
		{
			arrBoolean[i] = true;
		}
	}
}

int main()
{
	int m, n;
	std::cin >> m;

	while (m < 1 || m > 6)
	{
		std::cout << "Invalid input. Try again";
		std::cin >> m;
	}

	int possibleValuesLength = 0;

	constexpr int arrWithAllNDistinctDigitNumbersLength = 10 * 9 * 8 * 7 * 6 * 5 - 1;
	int arrWithAllNDistinctDigitNumbers[arrWithAllNDistinctDigitNumbersLength];

	int start = 1;
	int end = 1;
	for (int i = 0; i < m - 2; i++)
	{
		start *= 10;
	}

	end = start * 10 * 10 - 1;

	getAllNDigitNumbersWithDistinctDigits(start, end, arrWithAllNDistinctDigitNumbers, possibleValuesLength);
	bool arrWithAllNDistinctDigitNumbersPossibleCases[arrWithAllNDistinctDigitNumbersLength] = { 0 };

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		int userquery = 0;
		int bulls = 0; 
		int cows = 0;

		std::cin >> userquery >> bulls >> cows;

		//Validation
		if (bulls + cows > m || getDigitsCount(userquery) < m - 1)
		{
			std::cout << "Invalid input" << std::endl;
			i--;
			continue;
		}

		filterForNumber(userquery, bulls, cows, arrWithAllNDistinctDigitNumbers, arrWithAllNDistinctDigitNumbersPossibleCases, arrWithAllNDistinctDigitNumbersLength);
	}

	for (int i = 0; i < arrWithAllNDistinctDigitNumbersLength; i++)
	{
		if (arrWithAllNDistinctDigitNumbersPossibleCases[i] == false)
		{
			if (getDigitsCount(arrWithAllNDistinctDigitNumbers[i]) == m - 1)
			{
				std::cout << "0" << arrWithAllNDistinctDigitNumbers[i] << " ";
			}
			else
			{
				std::cout << arrWithAllNDistinctDigitNumbers[i] << " ";
			}
		}
	}
}