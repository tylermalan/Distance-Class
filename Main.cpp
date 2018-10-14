// CSS 342 
// Gordon Malan - started on 6 Oct 2018
// Program 1 - This file tests the Distance class

#include "Distance.h"
#include <iostream>

using namespace std;

int main()
{
	Distance d1(-5, 30), d2(5, -31), d3(2, 5), d4(1), d5, d6, d7(2.5, 3.4), d8(6.7);

	cout << "d1 = " << d1 << endl;
	cout << "d2 = " << d2 << endl;
	cout << "d3 = " << d3 << endl;
	cout << "d4 = " << d4 << endl;
	cout << "d5 = " << d5 << endl;
	cout << endl;

	cout << "Prepare to enter two integers to create a Distance object..." << endl;
	cin >> d6;
	cout << "d6 = " << d6 << endl;
	cout << endl;

	cout << "d7 (constructed with doubles) = " << d7 << endl;
	cout << "d8 (constructed with a single double) = " << d8 << endl;
	cout << endl;

	cout << "Testing d1.getFeet(): " << d1.getFeet() << endl;
	cout << "Testing d1.getInches(): " << d1.getInches() << endl;
	cout << endl;

	cout << "d1 + d2 = " << d1 + d2 << endl;
	cout << "d2 - d4 = " << d2 - d4 << endl;
	cout << "Sqfeet( d2 * d3 ) = " << d2 * d3 << endl;
	cout << "d1 / d2 = " << d1 / d2 << endl;
	cout << endl;

	cout << "( d1 += d2 ) = " << (d1 += d2) << endl;
	cout << "( d2 -= d4 ) = " << (d2 -= d4) << endl;
	cout << endl;

	cout << -d6 << endl;
	cout << endl;

	cout << "d1 is currently = " << d1 << endl;
	cout << "d2 is currently = " << d2 << endl;
	cout << "d3 is currently = " << d3 << endl;
	cout << "d1 < d2 is " << ((d1 < d2) ? "true" : "false") << endl;
	cout << "d1 > d2 is " << ((d1 > d2) ? "true" : "false") << endl;
	cout << "d1 <= d2 is " << ((d1 <= d2) ? "true" : "false") << endl;
	cout << "d2 >= d3 is " << ((d2 >= d3) ? "true" : "false") << endl;
	cout << "d1 == d2 is " << ((d1 == d2) ? "true" : "false") << endl;
	cout << "d1 != d2 is " << ((d1 != d2) ? "true" : "false") << endl;

	return 0;
}