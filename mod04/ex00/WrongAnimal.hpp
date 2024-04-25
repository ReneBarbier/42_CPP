#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(std::string const type);
		WrongAnimal(WrongAnimal const &copy);
		virtual ~WrongAnimal();
		WrongAnimal& operator = (const WrongAnimal &other);

		std::string getType() const;
		void makeSound() const;
};

#endif