/*

_____________________SURROUNDED_REGIONS_____________________

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells
and none of the region cells are on the edge of the board.
A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.


Example 1:

Input: board = 
[["X","X","X","X"],
["X","O","O","X"],
["X","X","O","X"],
["X","O","X","X"]]

Output: 
[["X","X","X","X"],
["X","X","X","X"],
["X","X","X","X"],
["X","O","X","X"]]

Explanation:
In the above diagram, the bottom region is not captured because it is on the edge of the board 
and cannot be surrounded.

Example 2:
Input: board = [["X"]]
Output: [["X"]]

*/

#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
private:
    struct Position {
        int x;
        int y;
    };

    vector<pair<int, int>> directions = { { 0, 1 }, { 0 , -1 }, { 1, 0 }, { -1, 0 } };

public:
    bool isValidMove(int x, int y, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        return ((x >= 0) && (x < n) && (y >= 0) && (y < m));
    }

    void DFS(vector<vector<char>>& board, Position position) {
        if ((!isValidMove(position.x, position.y, board)) || (board[position.x][position.y] != 'O')) {
            return;
        }

        board[position.x][position.y] = 'T';

        for (pair<int, int> d : directions) {
            Position new_position{ position.x + d.first, position.y + d.second };
            DFS(board, new_position);
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        
        int n = board.size();
        int m = board[0].size();

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                DFS(board, Position{ 0 , j });
            }
            if(board[n - 1][j] == 'O') {
                DFS(board, Position{ n - 1 , j });
            }
        }
    
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                DFS(board, Position{ i , 0 });
            }
            if (board[i][m - 1] == 'O') {
                DFS(board, Position{ i , m - 1 });
            }
        }
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};