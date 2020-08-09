#include <string>
#include <iostream>
#include <windows.h>
#include <cmath>
#include <vector>



const int MIN_DIMENTION = 10;

std::string Block[MIN_DIMENTION] = { "          " ,"          " ,"          " ,"          ", "    **    ", "    **    " ,"          " ,"          " ,"          " ,"          "};
std::string Boat[MIN_DIMENTION] = { "          " ,"          " ,"          " ,"   **     ", "   * *    ", "    *     " ,"          " ,"          " ,"          " ,"          " };
std::string Blinker[MIN_DIMENTION]= { "          " ,"          " ,"          " ,"          ", "   ***    ", "          " ,"          " ,"          " ,"          " ,"          " };
std::string Beacon[MIN_DIMENTION]= { "          " ,"          " ,"          " ,"   **     ", "   *      ", "      *   " ,"     **   " ,"          " ,"          " ,"          " };
class Matrix
{
private:
	int line;
	int column;	
	std::string **grid_matrix;


public:
	Matrix(size_t numColumnsX, size_t numLinesY)
	{
		line = numLinesY;
		column = numColumnsX;
		grid_matrix = new std::string*[line];
		for (int i = 0; i < line; i++) {
			grid_matrix[i] = new std::string[column];
		}
	}

	
	void setLine(size_t line_number, const std::string& data)
	{
		std::vector<char> vect_data(data.begin(), data.end());

		for (int i = 0; i < data.length(); i++) {
			grid_matrix[line_number][i] = vect_data[i];

		}
	}

	void setMatrix(Matrix mat,std::string shape[]) {
		for (int i = 0; i < MIN_DIMENTION; i++) {
			mat.setLine(i, shape[i]);
		}
	}

	void setCellXY(size_t x, size_t y, char cell_content)
	{
		// TODO: add functionality
		grid_matrix[y][x] = cell_content;
	}


	//Here I am verifing if a cell will be alive or dead, but I have some issues
	void liveOrDie(std::string mat[MIN_DIMENTION][MIN_DIMENTION]) {
		std::string mat2[MIN_DIMENTION][MIN_DIMENTION];
		for (int i = 0; i < MIN_DIMENTION; i++) {
			for (int j = 0; j < MIN_DIMENTION; j++) {
				mat2[i][j] = mat[i][j];                   //mat2 is a copy of my initial matrix
			}
		}

		for (int k = 1; k < MIN_DIMENTION-1; k++) {
			for (int l = 1; l < MIN_DIMENTION-1; l++) {
				int life = 0;
				for (int m = 0; m < 2; m++) {
					for (int n = 0; n < 2; n++) {
						if (m != 1 && n != 1) {
							if (mat2[m][n] == mat2[k][l])
								life++;
						}
					}
				}
				if (life < 2) {
					setCellXY(k, l, ' ');
				}
				else if (life == 2 || life == 3) {
						setCellXY(k, l, '*');
				}
				else if(life > 3) {
					setCellXY(k, l, ' ');
				}
			}
		}
	}

	void print()
	{
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < column; j++) {

				std::cout << grid_matrix[i][j];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};




int main()
{
	Matrix mat(20,10);
	mat.setMatrix(mat, Block);
	mat.print();
	//mat.liveOrDie;
	mat.setMatrix(mat, Boat);
	mat.print();
	mat.setMatrix(mat, Beacon);
	mat.print();

	

	//return 0;
}
