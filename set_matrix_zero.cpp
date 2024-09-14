/*

SET MATRIX ZERO

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

*/


#include <vector>
#include <unordered_set>
#include <stdexcept>  // Include this header for std::invalid_argument
#include <iostream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> colums;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    colums.insert(j);
                }
            }
        }

        unordered_set<int>::iterator it_rows = rows.begin();
        while (it_rows != rows.end()) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[*it_rows][j] = 0;
            }
            it_rows++;
        }

        unordered_set<int>::iterator it_colums = colums.begin();
        while (it_colums != colums.end()) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][*it_colums] = 0;
            }
            it_colums++;
        }
    }
};