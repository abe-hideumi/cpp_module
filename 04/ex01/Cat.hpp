#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain   *brain;

    public:
        // constructors
        Cat();
        Cat(const Cat &other);
        Cat    &operator=(const Cat &other);
        ~Cat();

        // member functions
        void makeSound() const;
        const Brain *getBrain() const;
        void setIdea(unsigned int index, const std::string &idea);
};

#endif
