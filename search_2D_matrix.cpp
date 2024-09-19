/*

___________________________SEARCH_A_2D_MATRIX___________________________

You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:
Input: matrix = 
				[[1,3,5,7],
				[10,11,16,20],
				[23,30,34,60]], 
target = 3
Output: true

Example 2:
Input: matrix = 
				[[1,3,5,7],
				[10,11,16,20],
				[23,30,34,60]], 
target = 13
Output: false


Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104


*/


#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int first = 0;
		int last = matrix.size() - 1;
		int med_row = (first + last) / 2;
		int med_col;

		while (first <= last) {
			med_row = (first + last) / 2;

			if ((matrix[med_row][0] <= target) && (matrix[med_row][matrix[0].size() - 1] >= target)) {
				break;
			}
			else if (matrix[med_row][0] > target) {
				last = med_row - 1;
			}
			else {
				first = med_row + 1;
			}
		}

		first = 0;
		last = matrix[0].size() - 1;
		med_col = (first + last) / 2;

		while (first <= last) {
			med_col = (first + last) / 2;

			if (matrix[med_row][med_col] == target) {
				return true;
			}
			else if (matrix[med_row][med_col] > target) {
				last = med_col - 1;
			}
			else {
				first = med_col + 1;
			}
		}

		return false;
	}
};


//int main() {
//	vector<vector<int>> matrix_1 = { {1, 3, 5, 7} ,{10, 11, 16, 20}, {23, 30, 34, 60} };
//	vector<vector<int>> matrix_2 = { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} };
//	int target = 11;
//	Solution sol;
//	sol.searchMatrix(matrix_2, target);
//	return 0;
//}