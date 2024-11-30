
#include <iostream>
#include "dateClassHeader.h"

using namespace std;




int main()
{
	Date test1;
	test1.print(1);
	
	Date test2(12,4,2000);
	test2.print(2);
	
	test1.setDate(6, 2, 2014);
	test1.print(3);
	
	test1.setDate(45, 13, 2018);
	test1.setDate(31, 4, 2000);
	test1.setDate(29, 2, 2009);

	test1.setDate(10, 4, 2014);
	test2.setDate(18, 4, 2014);
	cout << test1 - test2 << endl;

	test1.setDate(28, 2, 2006);
	test2.setDate(10, 11, 2003);
	cout << test1 - test2 << endl;

	test1.setDate(28, 2, 2008);
	--test1;
	test1.print(1);

	++test1;
	test1.print(1);

	test1--; 
	test1.print(1);
	test1++;
	test1.print(1);

	test1.setDate(31, 12, 2024);
	test1++;
	test1.print(1);

	test1--;
	test1.print(1);

	++test1;
	test1.print(1);
	--test1;
	test1.print(1);

	cin >> test1;
	
	cout << test1;
}

