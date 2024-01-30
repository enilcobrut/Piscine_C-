#include "Serializer.hpp"
#include "Data.h"

int	main(void)
{
	Data	a;
	a.value = 424322;

	std::cout << a.value << std::endl;

	uintptr_t	b = Serializer::serialize(&a);

	std::cout << b << std::endl;
	std::cout << Serializer::deserialize(b)->value << std::endl;

	return (0);
}