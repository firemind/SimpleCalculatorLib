#include "SimpleCalculator.h"

#include <istream>
#include <stdexcept>

int calc(int a, int b, char c) {
	switch (c) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0) {
			throw std::invalid_argument { "division by zero" };
		} else {
			return a / b;
		}
	case '%':
		if (b == 0) {
			throw std::invalid_argument { "modulo by zero" };
		} else {
			return a % b;
		}
	default:
		throw std::invalid_argument { "not a valid operator "+c };

	}
}

int calc(std::istream& in) {
	std::string input {""};
	int number1 {};
	int number2 {};
	char myChar {};
	in >> number1;

	in >> myChar;

	in >> number2;
	try {
		return calc(number1,number2,myChar);
	}
	catch( const std::invalid_argument& e ) {
	    return 0;
	}
}
