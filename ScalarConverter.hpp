#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <string>

enum Type {CHAR, FLOAT, DOUBLE, INTEGER, FLAG};

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);// AQUI?????????????????????????????
	static Type ParseType(const std::string &literal);
	static void Print(std::string str);
	static void Print(char c);
	static void Print(float n);
	static void Print(double n);
	static void Print(int n);
	static void Print_invalid();
	
public:
	~ScalarConverter();

	// Métodos
	static void convert(std::string literal);
};




#endif