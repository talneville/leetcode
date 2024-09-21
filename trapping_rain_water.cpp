/*

___________________________________TRAPPING_RAIN_WATER___________________________________

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Example 1:
	Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
	Output: 6
	Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
	In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
	Input: height = [4,2,0,3,2,5]
	Output: 9

Constraints:
	n == height.length
	1 <= n <= 2 * 104
	0 <= height[i] <= 105


*/


#include <vector>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() <= 2) {
			return 0;
		}

		vector<int> max_left = vector<int>(height.size());
		vector<int> max_right = vector<int>(height.size());
		vector<int> min_left_right = vector<int>(height.size());
		int current_max = 0;
		int trapped_rain = 0;

		for (int i = 0; i < height.size(); i++) {
			if (height[i] > current_max) {
				current_max = height[i];
			}
			max_left[i] = current_max;
		}
		
		current_max = 0;
		for (int i = height.size() - 1; i >= 0; i--) {
			if (height[i] > current_max) {
				current_max = height[i];
			}
			max_right[i] = current_max;
		}

		for (int i = 0; i < height.size(); i++) {
			min_left_right[i] = min(max_left[i], max_right[i]);
		}

		for (int i = 0; i < min_left_right.size(); i++) {
			int current_trapped_rain = min_left_right[i] - height[i];
			if (current_trapped_rain > 0) {
				trapped_rain += current_trapped_rain;
			}
		}

		return trapped_rain;
	}
};




/*

___________________________________TRAPPING_RAIN_WATER___________________________________
__________________________________TWO_POINTERS_SOLUTION__________________________________

*/


class Solution_2 {
public:
	int trap(vector<int>& height) {
		if (height.size() <= 2) {
			return 0;
		}

		int left = 0;
		int right = height.size() - 1;
		int max_left = height[left];
		int max_right = height[right];
		int trapped_rain = 0;
		int current_trapped_rain = 0;
		
		while (left < right) {
			if (max_left <= max_right) {
				left++;
				current_trapped_rain = max_left - height[left];
				if (current_trapped_rain > 0) {
					trapped_rain += current_trapped_rain;
				}				
				max_left = max(max_left, height[left]);
			}
			else {
				right--;
				current_trapped_rain = max_right - height[right];
				if (current_trapped_rain > 0) {
					trapped_rain += current_trapped_rain;
				}
				max_right = max(max_right, height[right]);
			}
		}
		return trapped_rain;
	}
};