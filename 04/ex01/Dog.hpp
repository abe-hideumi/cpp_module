#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain   *brain;

    public:
        // constructors
        Dog();
        Dog(const Dog &other);
        Dog    &operator=(const Dog &other);
        ~Dog();

        // member functions
        void makeSound() const;
        const Brain *getBrain() const;
        void setIdea(unsigned int index, const std::string &idea);
};

#endif
