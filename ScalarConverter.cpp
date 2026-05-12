#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <limits>
#include "ScalarConverter.hpp"

// Constructores
ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

// Destructor
ScalarConverter::~ScalarConverter()
{}

// Operador de asignación
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

static char to_char(const std::string &literal)
{
	if (literal.length() == 1)
		return literal[0];
	else
		return literal[1];
}

// Métodos
void ScalarConverter::convert(std::string literal)
{
	long n_long;
	float n_float;
	double n_double;
	char n_char;
	char *end;

	Type type = ScalarConverter::ParseType(literal);
	errno = 0;
	switch (type)
	{
		case FLAG:
			ScalarConverter::Print(literal);
			break;
		case CHAR:
			n_char = to_char(literal);
			Print(n_char);
			break;
		case FLOAT:
			n_float = strtof(literal.c_str(), &end);
			if (errno || &literal[literal.size() - 1] != end)
			{
				Print_invalid();
				break;
			}
			Print(n_float);
			break;
		case DOUBLE:
			n_double = strtod(literal.c_str(), &end);
			if (errno || *end != '\0')
			{
				Print_invalid();
				break;
			}
			Print(n_double);
			break;
		case INTEGER:
			n_long = strtol(literal.c_str(), &end, 10);
			if (errno || *end != '\0')
			{
				Print_invalid(); // ver nota*
				break;
			}
			if (n_long < std::numeric_limits<int>::min() || n_long > std::numeric_limits<int>::max())
				Print_invalid();
			else
				Print(static_cast<int>(n_long));
			break;
		case INVALID:
			Print_invalid();
			break;
	}
}

/*
NOTA:
segun subject:
"You have to first detect the type of the literal passed as a parameter, convert it from
string to its actual type, then convert it explicitly to the three other data types. Lastly,
display the results as shown below."
Si tengo que convertir primero al tipo original, un numero demasiado grande o demasiado
pequeño para su tipo es simplemente un argumento invalido.
*/
