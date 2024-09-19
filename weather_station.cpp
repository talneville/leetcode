/*

_________________________WEATHER_STATION_________________________

A weather station has measured temperatures during the last N days and N - 1 nights between them.
The measurements are given in an array of integers named temeratures listed in chreonologic order, starting with the day.

For example, temperatures = [10, 0, 2, -1, 4] means that the measurements were:
	- 10 degrees during the first day.
	- 0 degrees during the first night.
	- 2 degrees during the second day.
	- (-1) degrees during the second night.
	- 4 degrees during the last day.

The task is to calculate the number of warm nights during the recorded period.
A night is warm if the temparture was not more than 5 degrees colder than the tempratures measured on both the preceding 
and following days. 
In the example above, the second night was warm, but the first night was not.

Write a function:
	class Solution {
		public:
		int solution(int[] temperatures);
	};

that given an array named 'temperatures' returns the number of warm nights.

Example 1:
	For temperatures = [10, 0, 2, -1, 4] the function should return 1, as explained above.

Example 2:
	For temperatures = [15, 0, 3, -2, 3, -3, -1], only the second night was warm.
	the function should return 1.

Example 3:
	For temperatures = [-10, -5, 0, 10, 15, 10, 16], the first and second night were warm.
	Note that the second night is warm because the preceding day was colder and the following was only 5 degrees warmer.
	the function should return 2.
	
	
Assume that:
	- N is an integer within the range [2,...,100].
	- The length of array 'temperatures' is equal to 2N-1.
	- Each element of the array 'temperatures' is an integer within the range [-25,...,40].

In your solution, focus on correctness. 
The performance of your solution will not be the focus of the assessment.
	
*/

#include <vector>

using namespace std;

class Solution {
public:
	int solution(vector<int> temperatures) {
		int result = 0;
		for (int i = 1; i < temperatures.size() - 1; i += 2) {
			if ((temperatures[i - 1] - temperatures[i] <= 5) && (temperatures[i + 1] - temperatures[i] <= 5)) {
				result++;
			}
		}
		return result;
	}
};