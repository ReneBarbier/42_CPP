#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() 
{
    const Animal* meta = new Animal(); 
    const Animal* j = new Dog();
    const Animal* i = new Cat();
	const WrongAnimal* wc = new WrongCat();
    std::cout << j->getType() << " " << std::endl; //will output the dog type
    std::cout << i->getType() << " " << std::endl; //will output the cat type
	std::cout << wc->getType() << " " << std::endl; //will output the WrongCat type
	wc->makeSound(); //will output the wrong cat sound
    i->makeSound(); //will output the cat sound
    j->makeSound(); //will output the dog sound
    meta->makeSound(); //won't output anything because it's an Animal
	delete wc;
	delete i;
	delete j;
	delete meta;
    return 0; 
}