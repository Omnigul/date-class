#include <iostream>
#include "dateClassHeader.h"

using namespace std;


Date::Date()
{
	setDate();
}

Date::Date(int dayT, int monthT, int yearT)
{
	setDate(dayT, monthT, yearT);
}

void Date::setDate()
{
	day = 1;
	month = 1;
	year = 1930;
}

void Date::setDate(int dayT, int monthT, int yearT)
{
	if (yearT > 1929)
	{
		year = yearT;
	}
	else
	{
		cout << "error in setDate: year out of range" << endl;
		year = 1930;
	}

	if (0 < monthT < 13)
	{
		month = monthT;
	}
	else
	{ 
		cout << "error in setDate: month out of date" << endl;
		month = 1;
	}

	if (0 < dayT < monthDays(monthT) + 1)
	{
		day = dayT;
	}
	else
	{
		cout << "error in setDate: day out of range" << endl;
		day = 1;
	}
}

bool Date::leapYear(int yearT)
{
	if (yearT % 100 == 0)
	{
		if (yearT % 400 == 0)
		{
			return true;
		}
	}
	else if (yearT % 4 == 0)
	{
		return true;
	}
}

int Date::monthDays(int monthT)
{
	switch (monthT)
	{
	case 1:
		return 31;
	case 2:
		return 28;
	case 3:
		return 31;
	case 4:
		return 30;
	case 5:
		return 31;
	case 6:
		return 30;
	case 7:
		return 31;
	case 8:
		return 31;
	case 9:
		return 30;
	case 10:
		return 31;
	case 11:
		return 30;
	case 12:
		if (leapYear(year) == true)
		{
			return 31;
		}
		else
		{
			return 30;
		}
	}
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

void Date::print(int num)
{
	switch (num)
	{
	case 1:
		cout << month << "/" << day << "/" << year << endl;
		break;
	case 2:
		cout << monthName(month) << " " << day << ", " << year << endl;
		break;
	case 3:
		cout << day << " " << monthName(month) << " " << year << endl;
		break;
	default: 
		cout << "error in print: given format not in range" << endl;
	}
}

string Date::monthName(int monthT)
{
	switch (monthT)
	{
	case 1:
		return "January";
	case 2:
		return "Feburary";
	case 3:
		return "March";
	case 4:
		return "April";
	case 5:
		return "May";
	case 6:
		return "June";
	case 7:
		return "July";
	case 8:
		return "August";
	case 9:
		return "September";
	case 10:
		return "October";
	case 11:
		return "November";
	case 12:
		return "December";
	}
}

Date Date::operator++()
{	
	day++;
	if (day > monthDays(month))
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
	return *this;
}

Date Date::operator++(int)
{
	Date temp(day,month,year); 
	
	day++;
	if (day > monthDays(month))
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
	return temp;
}

Date Date::operator--()
{
	day--;
	if (day < 1)
	{
		month--;
		day = monthDays(month);
		if (month < 1)
		{
			month = 12;
			day = monthDays(month);
			year--;
		}
	}
	return *this;
}

Date Date::operator--(int)
{
	Date temp(day, month, year);
	day--;
	if (day < 1)
	{
		month--;
		day = monthDays(month);
		if (month < 1)
		{
			month = 12;
			day = monthDays(month);
			year--;
		}
	}
	return temp;
}

int Date::operator-(Date temp1)const
{
	int tally = 0;
	Date temp2;
	temp2 = temp1;
	while (temp2.day != day ||temp2.month != month || temp2.year != year)
	{
		if (day > temp2.day || month > temp2.month || year > temp2.year)
		{
			++temp2;
			tally++;
		}
		else
		{
			--temp2;
			tally++;
		}
	}
	return tally;
}

ostream& operator<<(ostream& strm, Date& temp)
{
	cout << temp.monthName(temp.month) << " " << temp.day << ", " << temp.year << endl;
	return strm;
}

istream& operator>>(istream& strm, Date& temp)
{
	strm >> temp.day;
	strm >> temp.month;
	strm >> temp.year;
	temp.setDate(temp.day, temp.month, temp.year);
	return strm;
}