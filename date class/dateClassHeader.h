#pragma once

#include <iostream>

using namespace std;



class Date
{
public:
	Date();
	Date(int dayT, int monthT, int yearT);
	void setDate();
	void setDate(int day, int month, int year);
	int getDay();
	int getMonth();
	int getYear();
	void print(int num);
	Date operator++(); 
	Date operator++(int);
	Date operator--();
	Date operator--(int);
	int operator-(const Date) const;
	friend ostream& operator<<(ostream&, Date&);
	friend istream& operator>>(istream&, Date&);

	
private:
	int day;
	int month;
	int year;
	bool leapYear(int year);
	int monthDays(int month);
	string monthName(int month);
};

