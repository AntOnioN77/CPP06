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

	//Use serialize() on the address of the Data object...
	uintptr_t return_value = Serializer::serialize(&data);
	//...and pass its return value to deserialize().
	Data *deserialized_data = Serializer::deserialize(return_value);
	if (deserialized_data == &data)
		std::cout << "Test OK :D" << std::endl;
	else
		std::cout << "Test Fail :( " << std::endl;
	return 0;
}
