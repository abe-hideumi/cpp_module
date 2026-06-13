#ifndef INPUT_HPP
#define INPUT_HPP

# include <iostream>
# include <string>

class	Input {
	private:
		std::string	fileName;
		std::string	s1;
		std::string	s2;

	public:
		Input();
		const std::string&	getFileName() const;
		const std::string&	getS1() const;
		const std::string&	getS2() const;
};

#endif
