#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "===== Basic tests =====" << std::endl;

    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();
    meta->makeSound();

    delete meta;
    delete dog;
    delete cat;


    std::cout << "\n===== Wrong tests =====" << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongAnimal->getType() << std::endl;
    std::cout << wrongCat->getType() << std::endl;

    wrongAnimal->makeSound();
    wrongCat->makeSound();

    delete wrongAnimal;
    delete wrongCat;


    std::cout << "\n===== Direct tests =====" << std::endl;

    Dog directDog;
    Cat directCat;
    WrongCat directWrongCat;

    directDog.makeSound();
    directCat.makeSound();
    directWrongCat.makeSound();

    return 0;
}
