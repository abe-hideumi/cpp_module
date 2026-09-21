#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), brain(new Brain()) {
    this->type = "Cat";
    std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat copy constructor" << std::endl;
}

Cat    &Cat::operator=(const Cat &other) {
    std::cout << "Cat copy assignment operator" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *this->brain = *other.brain;
    }
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

Brain *Cat::getBrain() const {
    return this->brain;
}
