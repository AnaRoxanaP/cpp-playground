#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++) {

		std::cout << argv[i] << "\n" << std::endl;
	}

	return 0;
}