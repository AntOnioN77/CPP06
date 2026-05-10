#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <string>

enum Type {CHAR, FLOAT, DOUBLE, INTEGER, FLAG, FAIL};

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);// AQUI?????????????????????????????

	
public:
	// Constructores
	virtual ~ScalarConverter();

	// Métodos
	static void convert(std::string literal);
};

Type ParseType(const std::string &literal);

#endif