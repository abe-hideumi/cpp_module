#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

// constructors

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << "Dog constructor" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copy constructor" << std::endl;
}

Dog    &Dog::operator=(const Dog &other) {
    std::cout << "Dog copy assignment operator" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor" << std::endl;
}

// member functions

void Dog::makeSound() const {
    std::cout << "Waon!" << std::endl;
}
