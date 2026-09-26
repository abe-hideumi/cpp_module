#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
    protected:
        std::string type;

    public:
        // constructors
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal    &operator=(const WrongAnimal &other);
        virtual ~WrongAnimal();

        // member functions
        std::string getType() const;
        void makeSound() const;
};

#endif // !WRONGANIMAL_HPP
