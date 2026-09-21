#include "Brain.hpp"
#include <iostream>

static const std::string   emptyIdea = "";

Brain::Brain() {
    std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructor" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}

Brain    &Brain::operator=(const Brain &other) {
    std::cout << "Brain copy assignment operator" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor" << std::endl;
}

const std::string &Brain::getIdea(unsigned int index) const {
    if (index >= 100)
        return emptyIdea;
    return this->ideas[index];
}

void Brain::setIdea(unsigned int index, const std::string &idea) {
    if (index < 100)
        this->ideas[index] = idea;
}
