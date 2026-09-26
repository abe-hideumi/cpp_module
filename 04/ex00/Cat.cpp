#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

// constructors

Cat::Cat() : Animal() {
    this->type = "Cat";
    std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor" << std::endl;
}

Cat    &Cat::operator=(const Cat &other) {
    std::cout << "Cat copy assignment operator" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor" << std::endl;
}

// member functions

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
