#include <iostream>
#include <string>
#include <vector>
#include <fstream>
//using namespace std;


/**
	Define a simple book.
*/
class Book
{
public:
	std::string name;
	std::string authors;

	void print()
	{
		std::cout << this->name << std::endl;
		std::cout << "\t(by " << this->authors << ")" << std::endl;
	}
};

/**
	Reads a vector of books from a text file.
	Note: the text file shall contain lines of text in pairs for the book name and authors
	E.g.
		BOOK 1
		AUTHOR 1
		BOOK 2
		AUTHOR 2
		BOOK 3
		AUTHOR 1, AUTHOR 2, AUTHOR 3
	@param file_name The name of the file to read from (must include path).
	@return Vector of books.
*/
std::vector<Book> readBooksFromTextFile(const std::string& file_name)
{
	/*std::vector<Book> results(NrBooks);
	vector<string> text(6);
	string lineFromFile;
	int cnt = 0,number=0;
	ifstream ReadFile(file_name);
	while (getline(ReadFile, lineFromFile)) {
		text[cnt] = lineFromFile;
		cnt++;
	}

	for (int i = 0; i < cnt; i++) {
		if (i % 2 == 0) {
			results[number].name = text[i];
			i++;
			results[number].authors = text[i];
		}
		
		number++;
	}*/

	// TODO: BEGIN read the file -------------------------------------

	std::vector<Book> results;
	std::vector<std::string> text;
	std::string lineFromFile;
	Book book;	

	std::ifstream ReadFile(file_name);

	if (ReadFile.fail()) {
		std::cout << "Your file did'n work" << std::endl;		
	}
	else
	{

		while (std::getline(ReadFile, lineFromFile)) {
			text.emplace_back(lineFromFile);
		}
		

		for (int i = 0; i < text.size(); i++) {
			if (i % 2 == 0) {
				book.name = text[i];
				i++;
				book.authors = text[i];
			}

			results.emplace_back(book);
		}

		ReadFile.close();
	}

	return results;

	// TODO: END read file and add to results vector ------------------
	
}

int main()
{
	// Read a collection of books from a file.
	// Simple examples can be found everywhere.
	// E.g. https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c

	// Read the data
	std::string input_data("../../data/ermahgerd_berks.txt");
	std::cout << "Reading the data from " << input_data << std::endl;
	std::vector<Book> books_from_file = readBooksFromTextFile(input_data);

	// Print the data
	std::cout << "Here are all the books found in the data file..." << std::endl;
	for (auto book : books_from_file)
	{
		book.print();
	}

	//std::ifstream ReadFile;

	return 0;
}