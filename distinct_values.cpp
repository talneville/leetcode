/*

__________________________________DISTINCT_VALUES__________________________________

There is an array A consisting of N integers.
How many distinct values can be obtained by calculating the absolute difference between two consecutive elements?

For example, given array A = [2, 5, 2, 7, 4], pairs of consecutive elements are: 
	- 2 and 5 (difference 3)
	- 5 and 2 (difference 3)
	- 2 and 7 (difference 5)
	- 7 and 7 (difference 3)
There are two distinct absolute differences values between elements (3 and 5).

Write a function:
	class Solution {
		public:
		int solution(int[] A);
	};

that given an array A, returns the number of distinct values that can be obtainted by calculating the absolute 
difference between two consecutive elements of A.

Example 1:
	Given A = [2, 5, 2, 7, 4], the function should return 2, as explained above.

Example 2:
	Given A = [0, 1, -2, 3, -4, 5], the function should return 5.
	The absolute value between consecutive pairs of elements are: 1, 3, 5, 7 and 9.

Example 3:
	Given A = [0, 0], the fuction should return 1.
	The absolut difference between the only two elements is 0.


Write an efficient algorithm for the follwing assumptions:
	- N is an integer within the range [2,...,100000].
	- Each element of array A is an integer withing the rang [-1000000000,...,1000000000].

*/

#include <unordered_set>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	int solution(vector<int> A) {
		if (A.size() < 2) {
			return 0;
		}
		unordered_set<int> absolute_difference = {};
		for (int i = 1; i < A.size(); i++) {
			absolute_difference.insert(abs(A[i] - A[i - 1]));
		}

		return absolute_difference.size();
	}
};
