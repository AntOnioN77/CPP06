#include "Serializer.hpp"
#include <iostream>

/*
Use serialize() on the address of the Data object and pass its return value to
deserialize(). Then, ensure the return value of deserialize() compares equal to the
original pointer.
*/

int main()
{
	Data data = {42, 'a'};
	Data control = {24, 'z'};

	//Use serialize() on the address of the Data object...
	uintptr_t return_value = Serializer::serialize(&data);
	//...and pass its return value to deserialize().
	Data *deserialized_data = Serializer::deserialize(return_value);
	if (deserialized_data == &data && deserialized_data != &control)
	{
		std::cout << "Las direcciones de memoria coinciden :D" << std::endl;
		std::cout << "Esperado: " << data.n << ". Obtenido: ";
		std::cout << deserialized_data->n << std::endl;
	}
	else
		std::cout << "Test Fail :( " << std::endl;
	return 0;
}
