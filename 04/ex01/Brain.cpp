#include "Brain.hpp"
#include <iostream>

static const std::string   emptyIdea = "";

// constructors

Brain::Brain() {
    std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructor" << std::endl;
    for (unsigned int i = 0; i < ideasCount; i++)
        this->ideas[i] = other.ideas[i];
}

Brain    &Brain::operator=(const Brain &other) {
    std::cout << "Brain copy assignment operator" << std::endl;
    if (this != &other) {
        for (unsigned int i = 0; i < ideasCount; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor" << std::endl;
}

// member functions

const std::string &Brain::getIdea(unsigned int index) const {
    if (index >= ideasCount)
        return emptyIdea;
    return this->ideas[index];
}

void Brain::setIdea(unsigned int index, const std::string &idea) {
    if (index < ideasCount)
        this->ideas[index] = idea;
}
