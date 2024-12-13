#include <iostream>

const int MATRIX_SIZE = 3;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int minElementInMatrix(const int matrix[][MATRIX_SIZE])
{
	int min = INT32_MAX;

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			if (matrix[i][j] < min)
			{
				min = matrix[i][j];
			}
		}
	}

	return min;
}

void printPrimaryDiagonal(const int matrix[][MATRIX_SIZE])
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		std::cout << matrix[i][i] << " ";
	}

	std::cout << std::endl;
}

void printSecondaryDiagonal(const int matrix[][MATRIX_SIZE])
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		std::cout << matrix[i][MATRIX_SIZE - 1 - i] << " ";
	}

	std::cout << std::endl;
}

void zigZagGalena(const int matrix[][MATRIX_SIZE])
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < MATRIX_SIZE; j++)
			{
				std::cout << matrix[i][j];
			}
		}
		else
		{
			for (int j = MATRIX_SIZE - 1; j > 0; j++)
			{
				std::cout << matrix[i][j];
			}
		}

		std::cout << std::endl;
	}


}

bool isMatrixTriangle(const int matrix[][MATRIX_SIZE])
{
	for (int i = 1; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (matrix[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

void trancponateMatrix(int matrix[][MATRIX_SIZE])
{
	for (int i = 1; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}

}

bool isMagixSquere(const int matrix[][MATRIX_SIZE])
{
	int sum = 0;
	int currSum = 0;

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		sum += matrix[0][i];
	}

	if (!(sumOfRows(matrix, sum)
		&& sumOfCols(matrix, sum)
		&& sumOfPeimaryDiagonal(matrix, sum)
		&& sumOfSecondaryDiagonal(matrix, sum)))
	{
		return false;
	}

	return true;
}

bool sumOfRows(const int matrix[][MATRIX_SIZE], int sum)
{
	for (int i = 1; i < MATRIX_SIZE; i++)
	{
		int currSum = 0;
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			currSum += matrix[i][j];
		}

		if (sum != currSum)
		{
			return false;
		}
	}

	return true;
}

bool sumOfCols(const int matrix[][MATRIX_SIZE], int sum)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		int currSum = 0;
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			currSum += matrix[j][i];
		}

		if (sum != currSum)
		{
			return false;
		}
	}

	return true;
}

bool sumOfPeimaryDiagonal(const int matrix[][MATRIX_SIZE], int sum)
{
	int currSum = 0;

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		currSum += matrix[i][i];
	}

	return sum == currSum;
}

bool sumOfSecondaryDiagonal(const int matrix[][MATRIX_SIZE], int sum)
{
	int currSum = 0;

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		currSum += matrix[i][MATRIX_SIZE - 1 - i];
	}

	return sum == currSum;
}

int main()
{
	std::cout << "Hello World!\n";
}