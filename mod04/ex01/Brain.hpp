#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		std::string ideas[100];

		Brain(void);
		Brain(Brain const &brain);
		~Brain(void);
		Brain &operator=(Brain const &brain);
};

#endif