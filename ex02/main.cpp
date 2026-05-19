#include "ABC.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Base * generate(void)
{
	int random = rand();
	if(random % 3 == 0)
	{
		std::cout << "A\n";
	}
	else if(random % 2 == 0)
	{
		std::cout << "B\n";
	}
	else
	{
		std::cout << "C\n";
	}


}

int main(void)
{

	unsigned int seed = static_cast <unsigned int>(time(NULL));
	srand(seed);
	for(int i =0; i<10 ;i++)
		generate();

	return 0;
}