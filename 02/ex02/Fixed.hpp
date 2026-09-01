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

        bool operator>( Fixed const & rhs ) const;
        bool operator<( Fixed const & rhs ) const;
        bool operator>=( Fixed const & rhs ) const;
        bool operator<=( Fixed const & rhs ) const;
        bool operator==( Fixed const & rhs ) const;
        bool operator!=( Fixed const & rhs ) const;

        Fixed operator+( Fixed const & rhs ) const;
        Fixed operator-( Fixed const & rhs ) const;
        Fixed operator*( Fixed const & rhs ) const;
        Fixed operator/( Fixed const & rhs ) const;

        Fixed & operator++( void );       // 前置 ++a
        Fixed   operator++( int );        // 後置 a++
        Fixed & operator--( void );       // 前置 --a
        Fixed   operator--( int );        // 後置 a--

        static Fixed & min( Fixed & a, Fixed & b );
        static Fixed const & min( Fixed const & a, Fixed const & b );
        static Fixed & max( Fixed & a, Fixed & b );
        static Fixed const & max( Fixed const & a, Fixed const & b );
};

std::ostream &operator<<(std::ostream & o, Fixed const & rhs);

#endif
