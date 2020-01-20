#include "ra/random.hpp"

using namespace ra::random;
linear_congruential_generator::linear_congruential_generator(linear_congruential_generator::int_type a, 
	linear_congruential_generator::int_type c, linear_congruential_generator::int_type m, linear_congruential_generator::int_type s)
{
		if ((s >= 0) && (s < m))
		{
			//Good
			mA = a;
			mC = c;
			mM = m;
			mS = s;

			if (((c % m) == 0) && ((s % m) == 0))
			{
				mXi_temp = 1;
			}
			else
			{
				mXi_temp = s;
			}

			mXi = mXi_temp;

		}
		else
		{
			//Error Case
			std::cout << "Invalid Parameters \n";
		}
}

linear_congruential_generator::linear_congruential_generator(const linear_congruential_generator& copy)
{
	mA = copy.mA;
	mC = copy.mC;
	mM = copy.mM;
	mS = copy.mS;
	mXi_temp = copy.mXi_temp;
}
	
linear_congruential_generator::int_type linear_congruential_generator::multiplier () const
{
	return mA;
}

linear_congruential_generator::int_type linear_congruential_generator::increment() const
{
	return mC;
}
linear_congruential_generator::int_type linear_congruential_generator::modulus() const
{
	return mM;
}
linear_congruential_generator::int_type linear_congruential_generator::default_seed()
{
	return 1.0f;
}
void linear_congruential_generator::seed(linear_congruential_generator::int_type s)
{
	if (((mC % mM) == 0) && ((s % mM) == 0))
	{
		mXi_temp = 1;
	}
	else
	{
		mXi_temp = s;
	}
	mXi = mXi_temp;
}

linear_congruential_generator::int_type linear_congruential_generator::operator()()
{
	mXi_temp = ((mA * mXi_temp) + mC) % mM;
	mXi = mXi_temp;

	return mXi; 
}

/* Discards the next n numbers in the generated sequence
*
*/
void linear_congruential_generator::discard(unsigned long long n)
{
	linear_congruential_generator::int_type temp;

	for (int i = 0; i < n; i++)
	{
		mXi_temp = ((mA * mXi) + mC) % mM;
	}
}

linear_congruential_generator::int_type linear_congruential_generator::min() const
{
	linear_congruential_generator::int_type min = mM;
	linear_congruential_generator::int_type x = mXi;

	for (int i = 0; i < mM; i++)
	{
		x = ((mA * x) + mC) % mM;
		
		if (mXi < min)
		{
			min = x;
		} 
	}

	return min;
}

linear_congruential_generator::int_type linear_congruential_generator::max() const
{
	linear_congruential_generator::int_type max = 0;
	linear_congruential_generator::int_type x = mXi;

	for (int i = 0; i < mM; i++)
	{
		x = ((mA * x) + mC) % mM;
		
		if (x > max)
		{
			max = x;
		} 
	}

	return max;
}
bool linear_congruential_generator::operator==(const linear_congruential_generator& compare)
{
	bool RetVal = true;
	
	if (this->mA != compare.mA)
	{
		RetVal = false;
	}
	if (this->mC != compare.mC)
	{
		RetVal = false;
	}
	if (this->mM != compare.mM)
	{
		RetVal = false;
	}
	if (this->mXi != compare.mXi)
	{
		RetVal = false;
	}

	return RetVal; 

}
bool linear_congruential_generator::operator!=(const linear_congruential_generator& compare)
{
	bool RetVal = true;

	if (this->mA == compare.mA)
	{
		RetVal = false;
	}
	if (this->mC == compare.mC)
	{
		RetVal = false;
	}
	if (this->mM == compare.mM)
	{
		RetVal = false;
	}
	if (this->mXi == compare.mXi)
	{
		RetVal = false;
	}

	return RetVal; 
}

std::ostream& ra::random::operator<<(std::ostream& out, const linear_congruential_generator& lcg)
{
	out << lcg.multiplier() << " " << lcg.increment() << " " << lcg.modulus() << " " << lcg.mXi;

	return out;
}	
