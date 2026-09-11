#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal() : type("") {
    std::cout << "Animal constructor\n";
}

Animal::~Animal() {
    std::cout << "Animal destructor\n";
}

std::string Animal::getType() const {
    return(this->type);
}

void    Animal::makeSound() const {
    std::cout << "Animal sound\n";
}
