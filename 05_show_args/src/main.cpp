#include <stdio.h>

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	
	std::string argumentAsString = argv[1];
	const char* argumentAsCharArray = argumentAsString.c_str();

	if (argc <= 1)
	{
		printf("No program arguments found.\n");
	}
	else {
		printf("&argumentAsCharArray\n");
	}

	



//	for (int i = 0; i < argumentAsString.length(); i++) {
	
		//printf("%s\n","This is a string");
		//printf("\n");
	//}




	return 0;
}