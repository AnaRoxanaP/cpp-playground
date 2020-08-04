#include <stdio.h>

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	
	if (argc <= 1)
	{
		printf("No program arguments found.\n");
	}

	
	std::string argumentAsString = argv[1];
	const char* argumentAsCharArray = argumentAsString.c_str();
	//char[argumentAsString.length()] charArray;

	for (int i = 0; i < argumentAsString.length(); i++) {
	
		printf(argv[i]);
		printf("/n");
	}




	return 0;
}