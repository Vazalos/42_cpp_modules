#include "Serializer.hpp"

int main()
{
    // Data* myData = NULL;
     
    // std::cout << &myData << '\n';

    // uintptr_t myDataInt = Serializer::serialize(myData);

    // std::cout << &myDataInt << '\n';

    // myData = Serializer::deserialize(myDataInt);

    // std::cout << &myData << '\n';

    	Data dt;

	dt.nothingBurger = 2;

	std::cout << "og adress: " << &dt << "\n";


	uintptr_t raw = Serializer::serialize(&dt);
	std::cout << "serialized: " << raw << "\n";

	Data* ptr = Serializer::deserialize(raw);
	std::cout << "deserialized " << ptr << "\n";

	if (ptr == &dt)
		std::cout << "gucci\n";
}