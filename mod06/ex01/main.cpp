#include "Serializer.hpp"

int main()
{
	Data data;

	data.name_player = "Rene";
	data.personal_highscore = 100;

	uintptr_t newPtr = Serializer::serialize(&data);
	Data *newData = Serializer::deserialize(newPtr);

	std::cout << newData->name_player << std::endl;
	std::cout << newData->personal_highscore << std::endl;

	return 0;
}
