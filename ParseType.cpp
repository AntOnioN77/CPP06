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
	
	if (literal.length() == 1 && !isdigit(literal[0]) ||
		literal.length() == 3 && literal[0] == '\'' && isascii(literal[1]) && literal[2] == '\'')
	{
		return true;
	}
	return false;
}

static bool is_float(const std::string &literal)
{
	if (literal.back() != 'F' && literal.back() != 'f')
		return false;
	if (literal.find('.') == std::string::npos)
		return false;
	return true;
}

static bool is_double(const std::string &literal)
{
	if (literal.find('.') == std::string::npos)
		return false;
	return true;
}

//innecesario, consideremos integuer lo que no entra a algun otro sitio
//y tras llamar a strtol(literal, 0, pnt) comprobar pnt == literal.end()
/* static bool is_integer(const std::string &literal)
{
	std::string::const_iterator it = literal.begin();
	if (*it == '-' || *it == '+')
		++it;
	if (literal.empty())
		return false;

	for ( it != literal.end(); ++it)
	{
		if (!isdigit(static_cast<unsigned char>(*it)))
			return false;
	}
	return true;
}
 */
//for ( std::string::iterator it=str.begin(); it!=str.end(); ++it)

Type ParseType(std::string &literal)
{
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