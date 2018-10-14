// CSS 342 
// Gordon Malan - started on 6 Oct 2018
// Program 1 - This file implements the Distance class

#include "Distance.h"

// Default constructor
Distance::Distance() {
	feet = 0;
	inch = 0;
}

// Single-argument constructor assumes that number represents feet
Distance::Distance(int feet) {
	this->feet = feet;
	inch = 0;
}

// Constructor that converts doubles to ints
Distance::Distance(double feet) {
	this->feet = static_cast<int>(round(feet));
	inch = 0;
}

// Constructor that converts floats to ints
Distance::Distance(float feet) {
	this->feet = static_cast<int>(roundf(feet));
	inch = 0;
}

// Conversion for overflow of inches takes place within this constructor
Distance::Distance(int feet, int inch) {
	this->feet = feet + (inch / 12);
	this->inch = inch % 12;
	if (this->feet < 0 && this->inch > 0) {
		this->feet += 1;
		this->inch -= 12;
	}
	else if (this->feet > 0 && this->inch < 0) {
		this->feet -= 1;
		this->inch = 12 + this->inch;
	}
}

// Constructor that converts doubles to ints
Distance::Distance(double feet, double inch) {
	this->feet = static_cast<int>(round(feet)) + (static_cast<int>(round(inch)) / 12);
	this->inch = static_cast<int>(round(inch)) % 12;
	if (this->feet < 0 && this->inch > 0) {
		this->feet += 1;
		this->inch -= 12;
	}
	else if (this->feet > 0 && this->inch < 0) {
		this->feet -= 1;
		this->inch = 12 + this->inch;
	}
}

// Constructor that converts floats to ints
Distance::Distance(float feet, float inch) {
	this->feet = static_cast<int>(roundf(feet)) + (static_cast<int>(roundf(inch)) / 12);
	this->inch = static_cast<int>(roundf(inch)) % 12;
	if (this->feet < 0 && this->inch > 0) {
		this->feet += 1;
		this->inch -= 12;
	}
	else if (this->feet > 0 && this->inch < 0) {
		this->feet -= 1;
		this->inch = 12 + this->inch;
	}
}

/*
///////////////////
END OF CONSTRUCTORS
///////////////////
*/

// Accessor methods
int Distance::getFeet() const {
	return feet;
}

int Distance::getInches() const {
	return inch;
}

// Returns an int representing an object converted to total inches
int Distance::convertToInches() const {
	return inch + (feet * 12);
}

// Converts a total number of inches into a Distance object
Distance Distance::convertToObject(int inches) const {
	int p = inches / 12;
	int o = inches % 12;
	Distance d(p, o);
	return d;
}

// Helper function for relational operator overloads
// Comapres objects via conversion to inches
int Distance::compareTo(const Distance& d2) const {
	int first = this->convertToInches();
	int second = d2.convertToInches();
	if (first < second) {
		return -1;
	}
	else if (first == second) {
		return 0;
	}
	else {
		return 1;
	}
}

// Functions to aid in operator overloading
// Returns a distance object that is the sum of two objects
Distance Distance::add(const Distance& d2) const {
	int first = this->convertToInches();
	int second = d2.convertToInches();
	int sum = first + second;
	return convertToObject(sum);
}

// Returns a distance object that is the difference between two objects
Distance Distance::subtract(const Distance& d2) const {
	int first = this->convertToInches();
	int second = d2.convertToInches();
	int sum = first - second;
	return convertToObject(sum);
}

// Returns a double representing the square feet contained within two objects
double Distance::multiply(const Distance& d2) const {
	int first = this->convertToInches();
	int second = d2.convertToInches();
	return static_cast<double>(first * second) / 12;
}

// Returns a double representing the proportion between two objects
double Distance::divide(const Distance& d2) const {
	int first = this->convertToInches();
	int second = d2.convertToInches();
	if (second == 0) {
		cout << "Error! You cannot divide by zero! ... ";
	}
	return static_cast<double>(first) / static_cast<double>(second);
}

// Define function operators for augmented operators
Distance& Distance::operator+=(const Distance& d2) {
	*this = add(d2);
	return *this;
}

Distance& Distance::operator-=(const Distance& d2) {
	*this = subtract(d2);
	return *this;
}

// Define function operator for unary negation
Distance Distance::operator-() {
	return Distance(-feet, -inch);
}

// Define function operator for output
// Consideration taken for 0, 1, and greater than 1
// values for both feet and inches
ostream& operator<<(ostream& out, const Distance& d) {
	int x = d.getFeet();
	int y = d.getInches();
	if (x == 0 && y == 0) {
		out << "0 inches";
	}
	else if (x == 0 && y == 1) {
		out << "1 inch";
	}
	else if (x == 0 && y > 1) {
		out << y << " inches";
	}
	else if (x == 1 && y == 0) {
		out << "1 foot";
	}
	else if (x > 1 && y == 0) {
		out << x << " feet";
	}
	else if (x == 1 && y == 1) {
		out << "1 foot 1 inch";
	}
	else if (x == 1 && y > 1) {
		out << "1 foot " << y << " inches";
	}
	else if (x > 1 && y == 1) {
		out << x << " feet" << " 1 inch";
	}
	else {
		out << x << " feet " << y << " inches";
	}
	return out;
}

// Define function operator for input and rejects input of negative numbers
istream& operator>>(istream& in, Distance& d) {
	cout << "Enter positive integer for feet: ";
	in >> d.feet;
	cout << endl;
	while (d.feet < 0) {
		cout << "Cannot enter negative number. Please reenter feet: ";
		in >> d.feet;
	}
	cout << "Enter positive integer between 0 and 11 for inches: ";
	in >> d.inch;
	cout << endl;
	while (d.inch < 0 || d.inch > 11) {
		cout << "Input out of bounds. Please reenter inches: ";
		in >> d.inch;
	}
	return in;
}

//Define nonmember function operators for comparison operators
bool operator<(const Distance& d1, const Distance& d2) {
	return d1.compareTo(d2) < 0;
}

bool operator<=(const Distance& d1, const Distance& d2) {
	return d1.compareTo(d2) <= 0;
}

bool operator>(const Distance& d1, const Distance& d2) {
	return d1.compareTo(d2) > 0;
}

bool operator>=(const Distance& d1, const Distance& d2) {
	return d1.compareTo(d2) >= 0;
}

bool operator==(const Distance& d1, const Distance& d2) {
	return d1.compareTo(d2) == 0;
}

bool operator!=(const Distance& d1, const Distance& d2) {
	return d1.compareTo(d2) != 0;
}

// Define nonmember function operators for arithmetic operators
Distance operator+(const Distance& d1, const Distance& d2) {
	return d1.add(d2);
}

Distance operator-(const Distance& d1, const Distance& d2) {
	return d1.subtract(d2);
}

double operator*(const Distance& d1, const Distance& d2) {
	return d1.multiply(d2);
}

double operator/(const Distance& d1, const Distance& d2) {
	return d1.divide(d2);
}
