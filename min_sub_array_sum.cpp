/*

MINIMUM SIZE SUB-ARRAY SUM

Given an array of positive integers nums and a positive integer target, return the minimal length of a
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.



Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

*/


#include <stdlib.h>
#include <vector>
#include <stdexcept>  // Include this header for std::invalid_argument
#include <iostream>
#include <limits>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (target <= 0) {
            throw invalid_argument("Target be greater than 0");
        }

        vector<int>::iterator it_left = nums.begin();
        vector<int>::iterator it_right = nums.begin();

        int sum = 0;
        int temp_sub_array_size = 0;
        int min_sub_array_size = numeric_limits<int>:: max();
       

        while (it_right != nums.end()) {
            sum += *it_right;
            temp_sub_array_size++;

            while (sum >= target) {
                if (temp_sub_array_size < min_sub_array_size) {
                    min_sub_array_size = temp_sub_array_size;
                }
                temp_sub_array_size--;
                sum -= *it_left;
                it_left++;
            }

            it_right++;
        }
        if (min_sub_array_size == numeric_limits<int>::max()) {
            return 0;
        }
        return min_sub_array_size;
    }
};