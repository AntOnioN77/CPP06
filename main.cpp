#include "ScalarConverter.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

static void test(const std::string &input, const std::string &description)
{
	std::cout << BOLD << CYAN << "═══════════════════════════════" << RESET << std::endl;
	std::cout << BOLD << YELLOW << "INPUT: \"" << input << "\"  (" << description << ")" << RESET << std::endl;
	ScalarConverter::convert(input);
}

int main(void)
{
	// FLAGS
	test("nan",    "double nan");
	test("nanf",   "float nan");
	test("+inf",   "double +inf");
	test("-inf",   "double -inf");
	test("+inff",  "float +inf");
	test("-inff",  "float -inf");

	// CHARS - single character
	test("a",   "char sin comillas");
	test("z",   "char sin comillas");
	test("'a'", "char con comillas");
	test("' '", "char espacio - non displayable?");

	// INTEGERS
	test("0",           "int cero");
	test("42",          "int positivo");
	test("-42",         "int negativo");
	test("2147483647",  "INT_MAX");
	test("-2147483648", "INT_MIN");
	test("2147483648",  "!!! INT_MAX + 1 - deberia ser todo impossible");
	test("-2147483649", "!!! INT_MIN - 1 - deberia ser todo impossible");

	// FLOATS
	test("0.0f",   "float cero");
	test("42.0f",  "float positivo");
	test("-4.2f",  "float negativo");
	test("1.f",    "float sin decimal tras punto");
	test(".5f",    "float sin entero");
	test("0.0F",   "float con F mayuscula");

	// DOUBLES
	test("0.0",   "double cero");
	test("42.0",  "double positivo");
	test("-4.2",  "double negativo");
	test("1.",    "double sin decimal tras punto");
	test(".5",    "double sin entero");

	// EDGE CASES
	test("32",   "int 32 - char espacio, non displayable");
	test("33",   "int 33 - char '!' displayable");
	test("127",  "int 127 - DEL, non displayable");
	test("128",  "int 128 - char impossible");
	test("-1",   "int -1 - char impossible");

	// CASOS PROBLEMATICOS
	test("",       "!!! string vacio");
	test("abc",    "!!! string invalido - deberia ser impossible");
	test("1.2.3",  "!!! doble punto");
	test("42f",    "!!! f sin punto - no es float");
	test("42.0ff", "!!! doble f");
	test(" 42",    "!!! espacio delante");

	return 0;
}