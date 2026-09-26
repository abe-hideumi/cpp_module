#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

// constructors

Dog::Dog() : Animal(), brain(new Brain()) {
    this->type = "Dog";
    std::cout << "Dog constructor" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copy constructor" << std::endl;
}

Dog    &Dog::operator=(const Dog &other) {
    std::cout << "Dog copy assignment operator" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *this->brain = *other.brain;
    }
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor" << std::endl;
}

// member functions

void Dog::makeSound() const {
    std::cout << "Waon!" << std::endl;
}

const Brain *Dog::getBrain() const {
    return this->brain;
}

void Dog::setIdea(unsigned int index, const std::string &idea) {
    this->brain->setIdea(index, idea);
}
