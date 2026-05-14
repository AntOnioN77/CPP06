#include "ScalarConverter.hpp"
#include <string>

static bool is_flag(const std::string &literal)
{
	if(literal == "-inf" || literal == "+inf" || literal == "-inff" ||
		literal == "+inff" || literal == "nanf" || literal == "nan")
	{
		return true;
	}
	return false;
}

static bool is_char(const std::string &literal)
{
	
	if ((literal.length() == 1 && !isdigit(literal[0])) ||
		(literal.length() == 3 && literal[0] == '\'' && isascii(literal[1]) && literal[2] == '\''))
	{
		return true;
	}
	return false;
}

static bool is_float(const std::string &literal)
{
	if (literal[literal.size() - 1] != 'F' && literal[literal.size() - 1] != 'f')
		return false;
	if (literal.find('.') == std::string::npos)
		return false;
	for (std::string::const_iterator it = (literal.begin()); it != literal.end(); ++it)
	{
		if (isdigit(*it))
			return true;
	}
	return false;
}

static bool is_double(const std::string &literal)
{
	if (literal.find('.') == std::string::npos)
		return false;
	for (std::string::const_iterator it = (literal.begin()); it != literal.end(); ++it)
	{
	if (isdigit(*it))
			return true;
	}
	return false;
}

Type ScalarConverter::ParseType(const std::string &literal)
{
	if (literal.empty())
		return INVALID;
	if (is_flag(literal))
		return FLAG;
	if (is_char(literal))
		return CHAR;
	if (is_float(literal))
		return FLOAT;
	if (is_double(literal))
		return DOUBLE;
	return INTEGER;
}
