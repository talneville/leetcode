/*

________________NUMBER_OF_ISLANDS________________

Given an m x n 2D binary grid grid which represents a map of '1's(land) and '0's(water), 
return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
["1", "1", "1", "1", "0"],
["1", "1", "0", "1", "0"],
["1", "1", "0", "0", "0"],
["0", "0", "0", "0", "0"]
]
Output : 1

Example 2 :
Input : grid = [
["1", "1", "0", "0", "0"],
["1", "1", "0", "0", "0"],
["0", "0", "1", "0", "0"],
["0", "0", "0", "1", "1"]
]
Output : 3

*/


#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    bool isValidPosition(int i, int j, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        return ((i >= 0) && (i < n) && (j >= 0) && (j < m));
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int number_of_islands = 0;
        
        queue<pair<int, int>> q;
       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    q.push({ i, j });
                    number_of_islands++;


                    while (q.empty() == false) {
                        // add neibours
                        pair<int, int> p = q.front();
                        q.pop();

                        if (isValidPosition(p.first - 1, p.second, grid) && grid[p.first - 1][p.second] == '1') {
                            q.push({ p.first - 1, p.second });
                            grid[p.first - 1][p.second] = '2';
                        }
                        if (isValidPosition(p.first + 1, p.second, grid) && grid[p.first + 1][p.second] == '1') {
                            q.push({ p.first + 1, p.second });
                            grid[p.first + 1][p.second] = '2';
                        }
                        if (isValidPosition(p.first, p.second + 1, grid) && grid[p.first][p.second + 1] == '1') {
                            q.push({ p.first, p.second + 1 });
                            grid[p.first][p.second + 1] = '2';
                        }
                        if (isValidPosition(p.first, p.second - 1, grid) && grid[p.first][p.second - 1] == '1') {
                            q.push({ p.first, p.second - 1 });
                            grid[p.first][p.second - 1] = '2';
                        }
                    }
                }
            }
        }

        return number_of_islands;
    }
};
