// CSS 342 
// Gordon Malan - started on 6 Oct 2018
// Program 1 - This is the header file for the Distance class

/*
It is assumed that if a driver program attempts to create a Distance
object by passing only one argument to the constructor, then that argument
will be treated as a 'feet' value.

Further, there are many constructors written here in order to handle cases where
either doubles or floats are passed in as arguments whenever an object
is instantiated.  I use the round function in these cases to round to
the nearest whole number, and then cast it as an integer.
*/

#ifndef Distance_H
#define Distance_H

#include <iostream>
#include <cmath>

using namespace std;

class Distance
{
private:
	int feet;
	int inch;

public:
	// Constructors
	Distance();
	Distance(int feet); // Assumed that only one number initialization means feet
	Distance(double feet);
	Distance(float feet);
	Distance(int feet, int inch);
	Distance(double feet, double inch);
	Distance(float feet, float inch);

	// Accessor methods
	int getFeet() const;
	int getInches() const;

	// Define helper function to assist with conversion
	int convertToInches() const;
	Distance convertToObject(int inches) const;
	int compareTo(const Distance& d2) const;

	// Define member functions to assist with operator overloading
	Distance add(const Distance& d2) const;
	Distance subtract(const Distance& d2) const;
	double multiply(const Distance& d2) const;
	double divide(const Distance& d2) const;

	// Define function operators for augmented operators
	Distance& operator+=(const Distance& d2);
	Distance& operator-=(const Distance& d2);

	// Define function operator for unary negation
	Distance operator-();

	// Define the << and >> operators
	friend ostream& operator<<(ostream& out, const Distance& d);
	friend istream& operator>>(istream& in, Distance& d);
};

// Define nonmember function operators for comparison operators
bool operator<(const Distance& d1, const Distance& d2);
bool operator<=(const Distance& d1, const Distance& d2);
bool operator>(const Distance& d1, const Distance& d2);
bool operator>=(const Distance& d1, const Distance& d2);
bool operator==(const Distance& d1, const Distance& d2);
bool operator!=(const Distance& d1, const Distance& d2);

// Define nonmember function operators for arithmetic operators
Distance operator+(const Distance& d1, const Distance& d2);
Distance operator-(const Distance& d1, const Distance& d2);
double operator*(const Distance& d1, const Distance& d2);
double operator/(const Distance& d1, const Distance& d2);

#endif // Distance_H