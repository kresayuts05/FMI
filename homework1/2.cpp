#include <iostream>
//Global variables
//Constraints
//Years
const int MAX_YEAR_VALUE = INT32_MAX;
const int MIN_YEAR_VALUE = INT32_MIN;

//Months
const int MAX_MONTH_VALUE = 12;
const int MIN_MONTH_VALUE = 1;

//Days
const int MAX_DAYS_VALUE = 31;
const int MIN_DAYS_VALUE = 1;

//[January -> 31 days] 
constexpr int daysInMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isValidInput(int subject, int min, int max)
{
	return subject >= min && subject <= max;
}

bool isValidDay(int day)
{
	return isValidInput(day, MIN_DAYS_VALUE, MAX_DAYS_VALUE);
}

bool isValidMonth(int month)
{
	return isValidInput(month, MIN_MONTH_VALUE, MAX_MONTH_VALUE);
}

bool isValidYear(int year)
{
	return isValidInput(year, MIN_YEAR_VALUE, MAX_YEAR_VALUE);
}

bool isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return true;
	}

	return false;
}

//this function calculeted days between dates, only including the end day!
int getCountOfDaysBetweenDates(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear)
{
	//VALIDATION

	// Check if the input values are valid. Invalid cases: non positive values(exept for the year = 0) or bigger than 
	// the max posible value;
	if (!(isValidYear(startYear) && isValidYear(endYear)))
	{
		return -1;
	}

	if (!(isValidMonth(startMonth) && isValidMonth(endMonth)))
	{
		return -1;
	}

	if (!(isValidDay(startDay) && isValidDay(endDay)))
	{
		return -1;
	}

	//Check validity of dates. Cases: if starts date is after the end date
	if (startYear > endYear)
	{
		return -1;
	}

	if (startMonth > endMonth && startYear == endYear)
	{
		return -1;
	}

	if (startDay > endDay && startMonth == endMonth && startYear == endYear)
	{
		return -1;
	}

	//Main logic

	int totaldays = 0;

	//add days from all full years
	for (int i = startYear + 1; i < endYear; i++)
	{
		totaldays += isLeapYear(i) ? 366 : 365;
	}

	//add days from all full months
	if (endYear - startYear > 0)
	{
		for (int i = startMonth; i < MAX_MONTH_VALUE; i++)
		{
			totaldays += daysInMonths[i];
		}

		for (int i = 0; i < endMonth - 1; i++)
		{
			totaldays += daysInMonths[i];
		}
	}
	else
	{
		for (int i = startMonth; i < endMonth - 1; i++)
		{
			totaldays += daysInMonths[i];
		}
	}

	//add the rest of the days is start and end months
	if (startMonth == endMonth && startYear == endYear)
	{
		totaldays += endDay - startDay;
	}
	else
	{
		totaldays += daysInMonths[startMonth - 1] - startDay;
		totaldays += endDay;
	}

	//add 1 day if start of end, or both years are leap years
	if (isLeapYear(startYear) && startMonth <= 2)
	{
		totaldays++;
	}

	//if the dates are in the same leap year it should not add additional day
	if ((isLeapYear(endYear) && endMonth >= 2) && (startYear != endYear))
	{
		totaldays++;
	}

	return totaldays;
}

void printDateAfter(int day, int month, int year, int countOfDays)
{
	//VALIDATION
	if (!isValidYear(year))
	{
		std::cout << "Invalid Year";
		return;
	}

	if (!isValidMonth(month))
	{
		std::cout << "Invalid Month";
		return;
	}

	if (!isValidDay(day))
	{
		std::cout << "Invalid Day";
		return;
	}

	if (countOfDays < 0)
	{
		std::cout << "Invalid count of days";
		return;
	}

	//Main logic
	int fullYears = countOfDays / 365;

	if (isLeapYear(year) && month == 2 && day + countOfDays > daysInMonths[1] + 1)
	{
		countOfDays--;
	}

	if (fullYears > 0)
	{
		for (int i = 0; i < fullYears; i++)
		{
			if (isLeapYear(year + 1))
			{
				countOfDays -= 1;
			}

			countOfDays -= 365;
			year++;
		}

		fullYears--;
	}

	int i = month - 1;
	while (countOfDays - daysInMonths[i] >= 0)
	{
		countOfDays -= daysInMonths[i];

		if (month + 1 == 13)
		{
			year++;
			month = 1;
			i = 0;
		}
		else
		{
			month++;
			i++;
		}

	}

	day += countOfDays;

	if (day >= daysInMonths[month - 1] + 1)
	{
		if (isLeapYear(year) && day > daysInMonths[month - 1] + 1 && month == 2)
		{
			day -= daysInMonths[month - 1] + 1;
			month++;
		}
		else
		{
			day -= daysInMonths[month - 1];
			month++;

			if (month == 13)
			{
				year++;
				month = 1;
			}
		}
	}

	std::cout << day << '.' << month << '.' << year;
}

void printDateBefore(int day, int month, int year, int countOfDays)
{
	//VALIDATION
	if (!isValidYear(year))
	{
		std::cout << "Invalid Year";
		return;
	}

	if (!isValidMonth(month))
	{
		std::cout << "Invalid Month";
		return;
	}

	if (!isValidDay(day))
	{
		std::cout << "Invalid Day";
		return;
	}

	if (countOfDays < 0)
	{
		std::cout << "Invalid count of days";
		return;
	}

	while (countOfDays > 0)
	{
		if (day > countOfDays)
		{
			day -= countOfDays;
			countOfDays = 0;
		}
		else
		{
			countOfDays -= day;
			month--;

			if (month < 1)
			{
				month = 12;
				year--;
			}

			if (isLeapYear(year) && month == 2)
			{
				day = daysInMonths[month-1] + 1;
			}
			else
			{
				day = daysInMonths[month-1];
			}

		}
	}

	std::cout << day << '.' << month << '.' << year;
}

int main()
{
	// function 1

	// corner cases
	//getCountOfDaysBetweenDates test
	//checked examples in a date calculator 
	//day month year
	// 2-2-2024 / 7-5-2024 = 95
	// 30-1-2020 / 12-3-2028 = 2964
	// 7-8-2022 / 31-12-2023 = 511
	// 5-2-2020 / 7-2-2023 = 1098

	/*int startDay;
	int endDay;
	int startMonth;
	int endMonth;
	int startYear;
	int endYear;

	std::cin >> startDay;
	std::cin >> startMonth;
	std::cin >> startYear;
	std::cin >> endDay;
	std::cin >> endMonth;
	std::cin >> endYear;

	std::cout << getCountOfDaysBetweenDates(startDay, startMonth, startYear, endDay, endMonth, endYear);*/

	// function 2

	// corner cases
	//checked examples in a date calculator 
	//day month year countOfDays  result
	//2.2.2024		763		6.3.2026
	//31.12.2020	3		3.1.2021
	//28.12.2023	75		12.3.2024
	//1.2.2020		2000	24.07.2025
	//2.2.2024		32		05.03.2024

	/*int day;
	int month;
	int year;
	int countDays;

	std::cin >> day;
	std::cin >> month;
	std::cin >> year;
	std::cin >> countDays;

	printDateAfter(day, month, year, countDays);*/

	// function 3

	/*int day;
	int month;
	int year;
	int countDays;

	std::cin >> day;
	std::cin >> month;
	std::cin >> year;
	std::cin >> countDays;

	printDateBefore(day, month, year, countDays);*/
}