#include <vector>
#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <utility>

using namespace std;

class Solution {


public:

	/* _________________________________FIBONACCI_________________________________*/

	int fibonacci(int n) {
		if (n <= 0) {
			return -1;
		}
		if (n <= 2) {
			return 1;
		}
		return fibonacci(n - 1) + fibonacci(n - 2);
	}

	int amazingFibonacci(int n) {
		if (n <= 0) {
			return -1;
		}
		double first_element = (1 + sqrt(5)) / 2;
		double second_element = (1 - sqrt(5)) / 2;
		double scalar_element = 1 / (sqrt(5));
		double result = (scalar_element * pow(first_element, n)) - (scalar_element * pow(second_element, n));
		return result;
	}

	// Do you want more information why can we do fibonnacci in O(1) and we can not do that in Pascal?
	// call me - 0522405048


	/* _________________________________PASCAL_________________________________*/

	vector<int> recursivePascal(int row) {
		if (row < 0) {
			return vector<int>(0);
		}
		if (row == 0) {
			return vector<int>(1, 1);
		}
		if (row == 1) {
			return vector<int>(2, 1);
		}

		vector<int> last_row_pascal = recursivePascal(row - 1);
		vector<int> result = vector<int>(last_row_pascal.size(), 1);

		for (int i = 1; i < result.size() - 1; i++) {
			result[i] = last_row_pascal[i - 1] + last_row_pascal[i];
		}

		return result;
	}

	vector<int> pascal(int row) {
		vector<int> factorial = vector<int>(row + 1, 1);
		vector<int> pascal = vector<int>(row + 1, 1);

		for (int i = 1; i < factorial.size(); i++) {
			factorial[i] = i * factorial[i - 1];
		}

		for (int i = 0; i < pascal.size(); i++) {
			pascal[i] = factorial[row] / (factorial[i] * factorial[row - i]);
		}

		return pascal;
	}

	vector<int> amazingPascal(int row) {
		vector<int> pascal = vector<int>(row + 1, 1);
		for (int i = 1; i < pascal.size(); i++) {
			pascal[i] = pascal[i - 1] * (row - i + 1) / i;
		}
		return pascal;
	}

	/* _________________________________SNAKE_________________________________*/

	struct Position {
		int x;
		int y;
	};

	void printBoard(const vector<vector<string>>& board) {
		for (const auto& row : board) {
			for (const auto& cell : row) {
				cout << cell << " ";
			}
			cout << endl;
		}
		cout << "----------------" << endl;
	}

	bool isValidMove(Position new_position, vector<vector<string>> board) {
		int n = board.size();
		return ((new_position.x >= 0) && (new_position.x < n) && 
					(new_position.y >= 0) && (new_position.y < n));
	}

	vector<Position> createSnake(vector<vector<string>> board) {
		int n = board.size();
		Position snake_head;
		vector<Position> snake;

		vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == "S") {
					snake_head.x = i;
					snake_head.y = j;
					snake.push_back(snake_head);
				}
			}
		}

		while (true) {
			bool found_next_s = false;

			for (pair<int, int>& d : directions) {
				int new_x = snake.back().x + d.first;
				int new_y = snake.back().y + d.second;

				if (((isValidMove({ new_x, new_y}, board) == true) && (board[new_x][new_y]) == "s")) {
					snake.push_back({ new_x, new_y });
					found_next_s = true;
					board[new_x][new_y] = " ";
					break;
				}
			}

			if (found_next_s == false) {
				break;
			}
		}

		return snake;
	}

	bool makeMove(vector<vector<string>>& board, vector<Position>& snake, Position new_position) {
		if (isValidMove(new_position, board) == false) {
			return false;
		}


		if (board[new_position.x][new_position.y] == "S") {
			return false;
		}
		else if (board[new_position.x][new_position.y] == "s") {
			return false;
		}
		else if (board[new_position.x][new_position.y] == "o") {
			return false;
		}
		else if (board[new_position.x][new_position.y] == "f") {
			board[new_position.x][new_position.y] = "S";
			board[snake.front().x][snake.front().y] = "s";

			snake.insert(snake.begin(), Position{ new_position.x , new_position.y });			
			return true;
		}
		else if (board[new_position.x][new_position.y] == " ") {
			board[new_position.x][new_position.y] = "S";
			board[snake.front().x][snake.front().y] = "s";
			board[snake.back().x][snake.back().y] = " ";

			snake.insert(snake.begin(), Position{ new_position.x , new_position.y });
			snake.pop_back();
			return true;
		}
		else {
			// Invalid case
			return false;
		}
	}

	bool snakePath(vector<vector<string>> board, string str) {
		vector<Position> snake = createSnake(board);

		for (char c : str) {
			if (c == 'U') {
				if (makeMove(board, snake, Position{snake.front().x - 1, snake.front().y }) == false) {
					return false;
				}
			}
			else if (c == 'D') {
				if (makeMove(board, snake, Position{ snake.front().x + 1, snake.front().y }) == false) {
					return false;
				}
			}
			else if (c == 'R') {
				if (makeMove(board, snake, Position{ snake.front().x, snake.front().y + 1 }) == false) {
					return false;
				}
			}
			else if (c == 'L') {
				if (makeMove(board, snake, Position{ snake.front().x, snake.front().y - 1 }) == false) {
					return false;
				}
			}
			else {
				return false;
			}

			printBoard(board);
		}

		return true;
	}

	/* _________________________________ISLAND_________________________________*/
    
};


int main() {
	Solution sol;
	vector<vector<string>> board = {
		 {" ", " ", " ", " ", " "},
		 {" ", "S", " ", "f", " "},
		 {" ", "s", " ", " ", " "},
		 {" ", "s", " ", " ", " "},
		 {" ", " ", " ", " ", " "}
	};
	string moves = "RRDD";
	sol.printBoard(board);

	if (sol.snakePath(board, moves)) {
		cout << "Game completed successfully!" << endl;
	}
	else {
		cout << "Game failed!" << endl;
	}

	return 0;
}