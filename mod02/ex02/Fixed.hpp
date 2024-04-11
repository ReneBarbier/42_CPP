#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;
	public:
		//==================== CONSTRUCTORS / DESTRUCTORS ====================//
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		~Fixed();
		//==================== COMPARASION OPERATORS ====================//
		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;
		//==================== ARITHMETIC OPERATORS ====================//	
		float operator+(const Fixed &fixed) const;
		float operator-(const Fixed &fixed) const;
		float operator*(const Fixed &fixed) const;
		float operator/(const Fixed &fixed) const;
		//==================== INCREMENT / DECREMENT OPERATORS ====================//
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
		//==================== GETTERS / SETTERS ====================//
		int getRawBits(void) const;
		void setRawBits(int const raw);
		//==================== CONVERSION FUNCTIONS ====================//
		int toInt(void) const;
		float toFloat(void) const;
		//==================== STATIC FUNCTIONS ====================//
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif