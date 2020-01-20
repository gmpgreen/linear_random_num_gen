#include <iostream>

namespace ra::random
{
	class linear_congruential_generator
	{
	public:
		typedef unsigned long long  int_type;
		static int_type default_seed();

		linear_congruential_generator(int_type a, int_type c, int_type m, int_type s = default_seed());
		linear_congruential_generator(const linear_congruential_generator & copy);
		int_type multiplier() const;
		int_type increment() const;
		int_type modulus() const;
		void seed(int_type s);
		int_type operator()();
		void discard(unsigned long long n);
		int_type min() const;
		int_type max() const;
		bool operator==(const linear_congruential_generator& compare);
		bool operator!=(const linear_congruential_generator& compare);

		int_type mXi; 		// Xi value

	private:
		int_type mXi_temp;	// temp Xi value
		int_type mA; 		// multiplier
		int_type mC; 		// increment
		int_type mM; 		// modulus
		int_type mS; 		// seed

	};

	std::ostream& operator<<(std::ostream &out, const linear_congruential_generator& lcg);
}
