#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    std::cout << j->getType() << " " << std::endl; //will output the dog type
    std::cout << i->getType() << " " << std::endl; //will output the cat type
    i->makeSound(); //will output the cat sound
    j->makeSound(); //will output the dog sound
	delete i;
	delete j;
    return 0; 
}