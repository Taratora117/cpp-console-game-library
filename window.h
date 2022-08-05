#include <iostream>
#include <unistd.h>

class Window {

	private:
		static const int height = 20;
		static const int width = 40;

		char matrix[height][width];

	public:
		void resetScreen() {
			printf("\033[2J");
			printf("\033[%d;%dH", 0, 0);
		}

		void fillWindow(char value) {
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					matrix[i][j] = value;
				}
			}
		}

		std::string getWindow(int row, int column) {return " ";} // TODO

		void setWindow(char**) {} // TODO

		char getWindowPixel(int row, int column) {
			return matrix[row][column];
		}

		void setWindowPixel(char value, int row, int column) {
			matrix[row][column] = value;
		}

		void movePixel(int fromRow, int fromColumn, int toRow, int toColumn) {
			matrix[toRow][toColumn] = matrix[fromRow][fromColumn];
			matrix[fromRow][fromColumn] = ' '; // TODO swap from and to or ' '
		}

		void draw() {
			resetScreen();
			for (int i = 0; i < height + 2; i++) {
				for (int j = 0; j < width + 2; j++) {
					if (i == 0 || i == height + 1) {
						std::cout << "-";
					} else if (j == 0 || j == width + 1) {
						std::cout << "|";
					} else {
						std::cout << matrix[i - 1][j - 1];
					}
				}
				std::cout << std::endl;
			}
		}

};