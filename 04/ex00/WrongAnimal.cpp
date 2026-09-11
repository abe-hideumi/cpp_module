#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("") {
    std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}
