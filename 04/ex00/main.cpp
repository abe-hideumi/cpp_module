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

    std::cout << "\n--- copy ---" << std::endl;
    Animal  copyMeta(*meta);
    Dog     copyDog(static_cast<const Dog&>(*dog));
    Cat     copyCat(static_cast<const Cat&>(*cat));
    copyMeta.makeSound();
    copyDog.makeSound();
    copyCat.makeSound();

    std::cout << "\n--- assign ---" << std::endl;
    Animal  otherMeta;
    Dog     otherDog;
    Cat     otherCat;
    otherMeta = *meta;
    otherDog = static_cast<const Dog&>(*dog);
    otherCat = static_cast<const Cat&>(*cat);
    otherMeta.makeSound();
    otherDog.makeSound();
    otherCat.makeSound();

    std::cout << "\n--- delete ---" << std::endl;
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

    std::cout << "\n--- copy ---" << std::endl;
    WrongAnimal copyWrongAnimal(*wrongAnimal);
    WrongCat    copyWrongCat(static_cast<const WrongCat&>(*wrongCat));
    copyWrongAnimal.makeSound();
    copyWrongCat.makeSound();

    std::cout << "\n--- assign ---" << std::endl;
    WrongAnimal otherWrongAnimal;
    WrongCat    otherWrongCat;
    otherWrongAnimal = *wrongAnimal;
    otherWrongCat = static_cast<const WrongCat&>(*wrongCat);
    otherWrongAnimal.makeSound();
    otherWrongCat.makeSound();

    std::cout << "\n--- delete ---" << std::endl;
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
