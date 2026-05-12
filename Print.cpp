#include <string>
#include <iostream>
#include "ScalarConverter.hpp"
#include <math.h>
#include <limits>
//#include <type_traits>

void ScalarConverter::Print(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << std::endl;
	std::cout << "double: " << str << std::endl;
}

void ScalarConverter::Print(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;

}

void ScalarConverter::Print(float n)
{
	std::cout << "char: ";
	if (n < 0 || n > 127 )
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<unsigned char>(n)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<unsigned char>(n) << std::endl;
	std::cout << "int: ";
	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(n) << std::endl;
	std::cout << "float: " << n << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void ScalarConverter::Print(double n)
{
	std::cout << "char: ";
	if (n < 0 || n > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<unsigned char>(n)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<unsigned char>(n) << std::endl;
	std::cout << "int: ";
	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(n) << std::endl;
	std::cout << "float: ";
	if (n < -std::numeric_limits<float>::max() || n > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << n << std::endl;
}

void ScalarConverter::Print(int n)
{
	std::cout << "char: ";
	if (n < 0 || n > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<unsigned char>(n)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<unsigned char>(n) << std::endl;
	std::cout << "int: ";
		std::cout << n << std::endl;
	std::cout << "float: ";
	if (n < -std::numeric_limits<float>::max() || n > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << n << std::endl;
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