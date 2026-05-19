#include "ABC.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
# define DEBUG_MODE 1

Base * generate(void)
{
	int random = rand();
	if(random % 3 == 0)
	{
		if(DEBUG_MODE)
			std::cout << "generated object: type A" << std::endl;
		return new A;
	}
	else if(random % 2 == 0)
	{
		if(DEBUG_MODE)
			std::cout << "generated object: type B" << std::endl;
		return new B;
	}
	else
	{
		if(DEBUG_MODE)
			std::cout << "generated object: type C" << std::endl;
		return new C;
	}
	return NULL;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "identify(): Object type A" << std::endl;
		return;
	}
	catch(std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "identify(): Object type B" << std::endl;
			return;
		}
		catch(std::exception& e)
		{
			std::cout << "identify(): Object type C" << std::endl;
			return;
		}
	}
}

void identify(Base* p)
{
	if (NULL != dynamic_cast<A*>(p))
	{
		std::cout << "identify(): Object type A" << std::endl;
		return;
	}
	else if (NULL != dynamic_cast<B*>(p))
	{
		std::cout << "identify(): Object type B" << std::endl;
		return;
	}
	std::cout << "identify(): Object type C" << std::endl;
	return;

}

int main(void)
{
	unsigned int seed = static_cast <unsigned int>(time(NULL));
	srand(seed);
	Base *pnt;
	std::cout <<"TEST 1 ----> identify(Base* p) <----" <<std::endl;
	for(int i =0; i<10 ;i++)
	{
		pnt = generate();
		identify(pnt);
		delete pnt;
		std::cout << "      ***\n";
	}

	std::cout <<"TEST 2 ----> identify(Base& p) <----" <<std::endl;
	for(int i =0; i<10 ;i++)
	{
		pnt = generate();
		identify(*pnt);
		delete pnt;
		std::cout << "      ***\n";
	}

	return 0;
}