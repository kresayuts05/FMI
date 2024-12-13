#include <iostream>
//
//		FIRST HALF
//		     |>
//		     |
//		     |
//		     |  //flag
// 
//		    / \ //roof   
// __	   /   \	 __
//|__| 	  /     \	|__|
//|__|	 /_______\	|__|
// 
//		SECOND HALF
//|__|				|__|
//|__|	    ___		|__|// 
//|__|	   |   |	|__|
//|__|  ___|   |___	|__|
// tower  door	floor	tower

//Global Constants

// N validation 
const int MIN_LEN = 1;
const int MAX_LEN = 23;

//flag 
char FLAG_BANNER_SYMBOL = '>';
char FLAG_STICK_SYMBOL = '|';

//roof
const char ROOF_SYMBOL_LEFT = '/';
const char ROOF_SYMBOL_RIGHT = '\\';
const char ROOF_SYMBOL_BOTTOM = '_';

//tower
const char TOWER_HORIZONTAL_SYMBOL = '_';
const char TOWER_VERTICAL_SYMBOL = '|';

//door
const char DOOR_HORIZONTAL_SYMBOL = '_';
const char DOOR_VERTICAL_SYMBOL = '|';

//floor
const char FLOOR_SYMBOL = '_';

//empty space
const char WHITE_SPACE = ' ';

void printWhiteSpacesHorizontally(unsigned t) 
{
	for (int i = 0; i < t; i++)
	{
		std::cout << WHITE_SPACE;
	}
}

void printSpecificCharNTimesVertically(char symbol, unsigned n, unsigned whiteSpacesBeforeSymbol)
{
	for (int i = 0; i < n; i++)
	{
		if (whiteSpacesBeforeSymbol > 0)
		{
			printWhiteSpacesHorizontally(whiteSpacesBeforeSymbol);
		}

		std::cout << symbol << std::endl;
	}
}

void printSpecificCharNTimesHorizontally(char symbol, unsigned n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << symbol;
	}
}

void printFlag(unsigned n)
{
	printWhiteSpacesHorizontally(3 * n + 2);

	std::cout << FLAG_STICK_SYMBOL << FLAG_BANNER_SYMBOL << std::endl;
	printSpecificCharNTimesVertically(FLAG_STICK_SYMBOL, 2 * n - 1, 3 * n + 2);
}

bool isValidInput(int n) 
{
	return n >= MIN_LEN && n <= MAX_LEN;
}

int main()
{
	//INPUT
	int n = 0;
	std::cout << "Въведете стойност за n от 1 до 23 включително." << std::endl;
	std::cin >> n;

	//VALIDATION
	while (!isValidInput(n))
	{
		std::cout << "Невалидна стойност. Моля въведете стойност за n от 1 до 23 включително." << std::endl;
		std::cin >> n;
	}

	//ROOF, 1/3 OF TOWERS -> FIRST HALF OF THE CASTLE
	//print flag
	printFlag(n);

	//half of the roof with height n 
	for (int i = 0; i < n - 1; i++)
	{
		printWhiteSpacesHorizontally(3 * n + 1 - i);

		std::cout << ROOF_SYMBOL_LEFT;
		printWhiteSpacesHorizontally(2 * (i + 1) - 1);
		std::cout << ROOF_SYMBOL_RIGHT << std::endl;
	}

	//Second half of the roof and 1/3 of the towers with height n
	for (int i = n - 1; i < 2 * n; i++)
	{
		//left tower part
		if (i == n - 1)
		{
			// if it is the middle row of the roof, where is the top of the tower, we need to add one white space
			//in order to center the top line of the tower 
			std::cout << WHITE_SPACE;
			printSpecificCharNTimesHorizontally(TOWER_HORIZONTAL_SYMBOL, n);
		}
		else
		{
			std::cout << TOWER_VERTICAL_SYMBOL;
			printSpecificCharNTimesHorizontally(TOWER_HORIZONTAL_SYMBOL, n);
			std::cout << TOWER_VERTICAL_SYMBOL;
		}

		//roof spacing from left tower
		if (i == n - 1)
		{
			//if it is the middle row, there is one additional space in the beggining of the row, because of the tower
			printWhiteSpacesHorizontally(2 * (i + 1) - n + 1);
		}
		else
		{
			printWhiteSpacesHorizontally(2 * n - i - 1);
		}

		//roof part
		std::cout << ROOF_SYMBOL_LEFT;
		if (i == 2 * n - 1)
		{
			//if it is the last row of the roof we need to use the bottom symbol, not white space, in order to devide 
			//the roof from the body of the castle
			printSpecificCharNTimesHorizontally(ROOF_SYMBOL_BOTTOM, 2 * (i + 1) - 1);
		}
		else
		{
			printWhiteSpacesHorizontally(2 * (i + 1) - 1);
		}
		std::cout << ROOF_SYMBOL_RIGHT;

		//roof spacing from the right tower
		if (i == n - 1)
		{
			//if it is the middle row, there we need one additional space in the beggining of the tower line
			//in order to center it
			printWhiteSpacesHorizontally(n); //2 * (i + 1) - n
		}
		else
		{
			printWhiteSpacesHorizontally(2 * n - i - 1);
		}

		//right tower part
		if (i == n - 1)
		{
			// if it is the middle row of the roof, where is the top of the tower, we need to add one white space
			//in order to center the top line of the tower 
			std::cout << WHITE_SPACE;
			printSpecificCharNTimesHorizontally(TOWER_HORIZONTAL_SYMBOL, n);
			std::cout << std::endl;
		}
		else
		{
			std::cout << TOWER_VERTICAL_SYMBOL;
			printSpecificCharNTimesHorizontally(TOWER_HORIZONTAL_SYMBOL, n);
			std::cout << TOWER_VERTICAL_SYMBOL << std::endl;
		}
	}

	//2/3 OF TOWERS, DOOR, FLOOR
	for (int i = 0; i < 2 * n; i++)
	{
		int doorWidth = n;

		if (n % 2 == 0) 
		{
			doorWidth += 1;
		}

		//left part of the tower
		std::cout << TOWER_VERTICAL_SYMBOL;
		printSpecificCharNTimesHorizontally(TOWER_HORIZONTAL_SYMBOL, n);
		std::cout << TOWER_VERTICAL_SYMBOL;

		//middle of the castle
		//Here we have 3 cases : first n-1 rows, then row n, next n rows
		if (i < n - 1)
		{
			printWhiteSpacesHorizontally(4 * n + 1);
		}
		else
		{
			//top of the door
			if (i == n - 1)
			{
				int func = (4 * n - 1 - doorWidth) / 2 + 1;

				printWhiteSpacesHorizontally(func);

				if (n == 1)
				{
					printSpecificCharNTimesHorizontally(DOOR_HORIZONTAL_SYMBOL, doorWidth);
				}
				else
				{
					printSpecificCharNTimesHorizontally(DOOR_HORIZONTAL_SYMBOL, doorWidth);
				}

				printWhiteSpacesHorizontally(func);
			}
			//middle of the door
			else
			{
				int func = (4 * n + 1 - doorWidth) / 2 - 1;
				if (i == 2 * n - 1)
				{
					printSpecificCharNTimesHorizontally(FLOOR_SYMBOL, func);
					std::cout << DOOR_VERTICAL_SYMBOL;

					if (n == 1)
					{
						printWhiteSpacesHorizontally(doorWidth);
					}
					else
					{
						printWhiteSpacesHorizontally(doorWidth);
					}

					std::cout << DOOR_VERTICAL_SYMBOL;
					printSpecificCharNTimesHorizontally(FLOOR_SYMBOL, func);
				}
				else
				{
					printWhiteSpacesHorizontally(func);
					std::cout << DOOR_VERTICAL_SYMBOL;

					if (n == 1)//doesn't work@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
					{
						printWhiteSpacesHorizontally(doorWidth);
					}
					else
					{
						printWhiteSpacesHorizontally(doorWidth);
					}

					std::cout << DOOR_VERTICAL_SYMBOL;
					printWhiteSpacesHorizontally(func);
				}
			}
		}

		//right part of the tower
		std::cout << TOWER_VERTICAL_SYMBOL;
		printSpecificCharNTimesHorizontally(TOWER_HORIZONTAL_SYMBOL, n);
		std::cout << TOWER_VERTICAL_SYMBOL << std::endl;
	}

}