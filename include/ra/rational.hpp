#include <iostream>
#include <cmath>
#include <numeric>

namespace ra::math
{
    template <typename T> 
    class rational
    {
    public:
        typedef T int_type;

        int_type *mRational_num = new int_type;  //quotient
        int_type *mX = new int_type;            //numerator
        int_type *mY = new int_type;            //denominator

        rational()
        {
            *mRational_num = 0;
            *mX = 0;
            *mY = 1;
        }
        rational(int_type num, int_type den = 1)
        {
            
            if (den != 0)
            {
                *mX = num;
                *mY = den;
                *mRational_num = *mX / *mY;
            }
            else
            {
                *mX = std::numeric_limits<int_type>::max();
                *mY = 1;
                *mRational_num = *mX / *mY;
            }
        }

        int_type numerator()
        {
            return *mX;
        }
        
        int_type denominator()
        {
            return *mY;
        }
        
        rational& operator+=(const rational& sub)
        {
            int_type num1 = *mX;
            int_type num2 = *(sub.mX);
            int_type den1 = *mY;
            int_type den2 = *(sub.mY);

            int_type common_den = std::gcd(den1, den2);

            // common denominator
            num1 *= den2;
            den1 *= den2;
            num2 *= den1;

            // Simplify by divind by gcd
            *mX = (num1 + num2) / common_den;
            *mY = den1 / common_den; 

            return this;
        }   
        rational& operator-=(const rational& sub)
        {   
            int_type num1 = mX;
            int_type num2 = sub.mX;
            int_type den1 = mY;
            int_type den2 = sub.mY;


            int_type common_den = gcd(den1, den2);

            // common denominator
            num1 *= den2;
            den1 *= den2;
            num2 *= den1;

            // Simplify by divind by gcd
            *mX = (num1 - num2) / common_den;
            *mY = den1 / common_den; 

            return this;
        }
        
        rational& operator*=(const rational& mul)
        {
            *mX *= *(mul.mX);
            *mY *= *(mul.mY);

            if (mY == 0)
            {
                *mX = std::numeric_limits<int_type>::max();
                *mY = 1;
            }
        }
        
        rational& operator/=(const rational& div)
        {
            *mX *= *div.mY;
            *mY *= *div.mX;
            
            if (mY == 0)
            {
                *mX = std::numeric_limits<int_type>::max();
                *mY = 1;
            }
        }

        int_type truncate()
        {
            float temp_var = *mX / *mY;
            *mRational_num = trunc(temp_var);
        }

        bool is_integer()
        {
            bool RetVal = std::numeric_limits<int_type>::is_integer;

            return RetVal;
        }
        
        bool operator!()
        {
            if (*mX == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool operator<(rational& rhs)
        {
            *mRational_num = *mX / *mY;

            if (*mRational_num < *(rhs.mRational_num))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        bool operator>(rational& rhs)
        {
            *mRational_num = *mX / *mY;

            if (*mRational_num > *(rhs.mRational_num))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        bool operator<=(rational& rhs)
        {
            *mRational_num = *mX / *mY;

            if (*mRational_num <= *(rhs.mRational_num))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        bool operator >=(rational& rhs)
        {
            *mRational_num = *mX / *mY;

            if (*mRational_num >= *(rhs.mRational_num))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        int_type operator++()
        {
            *mX += mY;
            *mRational_num = *mX / *mY;
        }

        int_type operator--()
        {
            *mX -= *mY;
            *mRational_num = *mX / *mY;
        }
    };

// TODO:
    // rational<class T>& operator+(rational<class T>& num); //positive of the rational
    // rational<class T>& operator-(rational<class T>& num);
    // rational<class T>& operator+(rational<class T>& num, rational<class T>& add);
    // rational<class T>& operator-(rational<class T>& num, rational<class T>& sub);
    
    // rational<class T>& operator*(rational<class T>& num, rational<class T>& mul);
    // rational<class T>& operator/(rational<class T>& num, rational<class T>& div);

    std::ostream& operator<<(std::ostream &out, rational<int>& num)
    {
        if (num.mRational_num < 0)
        {
            out << "-" << *num.mX << "/" << *num.mY;
        }
        else
        {
            out << *num.mX << "/" << *num.mY;
        }

        return out;
    }
// TODO:
    // rational<class T>& operator>>(std::istream &in, rational<class T>& num);
    
}