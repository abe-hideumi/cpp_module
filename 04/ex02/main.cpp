#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
    // Animal is abstract: the following lines must NOT compile.
    // Animal animal;
    // Animal* animal = new Animal();

    std::cout << "===== Subject test =====" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;
    }


    std::cout << "\n===== Animal array =====" << std::endl;
    {
        const int   size = 6;
        Animal*     animals[size];

        for (int i = 0; i < size; i++) {
            if (i < size / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        for (int i = 0; i < size; i++)
            animals[i]->makeSound();
        for (int i = 0; i < size; i++)
            delete animals[i];
    }


    std::cout << "\n===== Deep copy (Dog) =====" << std::endl;
    {
        Dog original;
        original.setIdea(0, "bone");

        Dog copy(original);
        Dog assigned;
        assigned = original;

        original.setIdea(0, "ball");

        std::cout << "original: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "copy    : " << copy.getBrain()->getIdea(0) << std::endl;
        std::cout << "assigned: " << assigned.getBrain()->getIdea(0) << std::endl;
        std::cout << "brain address differs: "
                  << (original.getBrain() != copy.getBrain()
                      && original.getBrain() != assigned.getBrain()) << std::endl;
    }


    std::cout << "\n===== Deep copy (Cat) =====" << std::endl;
    {
        Cat original;
        original.setIdea(0, "fish");

        Cat copy(original);
        Cat assigned;
        assigned = original;

        original.setIdea(0, "mouse");

        std::cout << "original: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "copy    : " << copy.getBrain()->getIdea(0) << std::endl;
        std::cout << "assigned: " << assigned.getBrain()->getIdea(0) << std::endl;
        std::cout << "brain address differs: "
                  << (original.getBrain() != copy.getBrain()
                      && original.getBrain() != assigned.getBrain()) << std::endl;
    }

    std::cout << "\n===== Self-assignment =====" << std::endl;
    {
        Dog dog;
        dog.setIdea(0, "bone");
        Dog &dogRef = dog;
        dog = dogRef;
        std::cout << "dog idea : " << dog.getBrain()->getIdea(0) << std::endl;

        Cat cat;
        cat.setIdea(0, "fish");
        Cat &catRef = cat;
        cat = catRef;
        std::cout << "cat idea : " << cat.getBrain()->getIdea(0) << std::endl;
    }

    return 0;
}
