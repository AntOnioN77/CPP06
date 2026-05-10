#include "ScalarConverter.hpp"
#include <ctype.h>
#include <stdlib.h>

// Constructores
ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{}

// Destructor
ScalarConverter::~ScalarConverter()
{}

// Operador de asignación
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
/* 	if (this != &other)
	{
		attribute = other.attribute;
	} */
	return *this;
}

// Métodos
void ScalarConverter::convert(std::string literal)
{
	int n_int;
	float n_float;
	double n_double;
	char n_char;
	Type type = ParseType(literal);




}

