#ifndef Serializer_HPP
# define Serializer_HPP

# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serializer {
private:
	// Atributos
	std::string attribute;
	// Constructores
	Serializer();
	Serializer(const Serializer &other);
public:
	~Serializer();
	Serializer &operator=(const Serializer &other);
	// Métodos

	//It takes a pointer and converts it to the unsigned integer type uintptr_t.
	static uintptr_t serialize(Data* ptr);
	//It takes an unsigned integer parameter and converts it to a pointer to Data.
	static Data* deserialize(uintptr_t raw);
};

#endif