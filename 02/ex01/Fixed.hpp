#ifndef FIXED_HPP
# define FIXED_HPP

 # include <iostream>

class Fixed {

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed( void );
		Fixed( Fixed const & src );
		~Fixed( void );
		Fixed( const int n );
		Fixed( const float n );
		Fixed & operator=( Fixed const & rhs );

		int toInt(void) const;
		float toFloat(void) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

std::ostream &operator<<(std::ostream & o, Fixed const & rhs);

#endif
