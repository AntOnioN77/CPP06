#include <string>
#include <iostream>
#include "ScalarConverter.hpp"
#include <math.h>
#include <limits>
#include <cmath>

void ScalarConverter::Print(const std::string &str)
{
	std::string to_print = str;
	if (to_print == "-inff" || to_print == "+inff" || to_print == "nanf")
		to_print.erase(to_print.length() - 1);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << to_print << "f" << std::endl;
	std::cout << "double: " << to_print << std::endl;
}

void ScalarConverter::Print(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::Print(float n)
{
	bool is_fractional = (std::fmod(n, 1.0) != 0.0);

	std::cout << "char: ";
	if  (n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!isgraph(static_cast<int>(n)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<unsigned char>(n) << std::endl;
	std::cout << "int: ";
	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(n) << std::endl;
	std::cout << "float: " << n << (is_fractional ? "f" : ".0f") << std::endl;
	std::cout << "double: " << static_cast<double>(n) << (is_fractional ? "" : ".0") << std::endl;
}

void ScalarConverter::Print(double n)
{
	bool is_fractional = (std::fmod(n, 1.0) != 0.0);

	//char
	std::cout << "char: ";
	if (n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!isgraph(static_cast<int>(n)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<unsigned char>(n) << std::endl;
	//int
	std::cout << "int: ";
	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(n) << std::endl;
	//float
	std::cout << "float: ";
	if (n < -std::numeric_limits<float>::max() || n > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(n) << (is_fractional ? "f" : ".0f") << std::endl;
	//double
	std::cout << "double: " << n << (is_fractional ? "" : ".0") << std::endl;
}

void ScalarConverter::Print(int n)
{
	std::cout << "char: ";
	if  (n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!isgraph(static_cast<int>(n)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<unsigned char>(n) << std::endl;
	std::cout << "int: ";
		std::cout << n << std::endl;
	std::cout << "float: ";
	if (n < -std::numeric_limits<float>::max() || n > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void ScalarConverter::Print_invalid()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}


/*void print(float n);
void print(double n);
void print(int); 
void Print_invalid();*/


/* /convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0 */