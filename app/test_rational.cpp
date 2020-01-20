#include <iostream>
#include "ra/rational.hpp"

using namespace ra::math;

int main()
{
	rational test_obj1 = rational<int>(5, 6);


	std::cout << test_obj1;

	return 0;
}