#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
    public:
        // constructors
        Cat();
        Cat(const Cat &other);
        Cat    &operator=(const Cat &other);
        ~Cat();

        // member functions
        void makeSound() const;
};

#endif
