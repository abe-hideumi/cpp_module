#include "Animal.hpp"
#include <iostream>

// constructors

Animal::Animal() : type("") {
    std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << "Animal copy constructor" << std::endl;
}

Animal    &Animal::operator=(const Animal &other) {
    std::cout << "Animal copy assignment operator" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor" << std::endl;
}

// member functions

std::string Animal::getType() const {
    return(this->type);
}
