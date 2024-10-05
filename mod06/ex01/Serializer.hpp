#pragma once

#include <iostream>
#include <stdint.h>

typedef struct s_Data {
	std::string	name_player;
	int			personal_highscore;
} 	Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&); 
		~Serializer();
	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};
