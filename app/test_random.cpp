#include <iostream>
#include "ra/random.hpp"

using namespace ra::random;
int main()

{
	linear_congruential_generator test_obj = linear_congruential_generator(1.0f, 2.0f, 20.0f);
	std::cout << test_obj;
	
	test_obj.discard(5);
	std::cout << test_obj;

	for (int i = 0; i<25; i++)
	{	
		std::cout << "\n" << test_obj();
	}



	return 0;
}