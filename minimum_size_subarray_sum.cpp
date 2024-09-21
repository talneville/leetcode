/*

___________________________________MINIMUM_SIZE_SUBARRAY_SUM___________________________________

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
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


Constraints:
    1 <= target <= 109
    1 <= nums.length <= 105
    1 <= nums[i] <= 104


*/


#include <vector>
#include <stdexcept>
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
        int min_sub_array_size = numeric_limits<int>::max();


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




class Solution_2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int min_length = numeric_limits<int>::max();
        int temp_length = 0;

        while (right < nums.size()) {
            sum += nums[right];
            temp_length++;

            while ((sum >= target) && (left <= right)) {
                if (temp_length < min_length) {
                    min_length = temp_length;
                }
                sum -= nums[left];
                temp_length--;
                left++;
            }
            right++;
        }

        if (min_length == numeric_limits<int>::max()) {
            return 0;
        }
        return min_length;
   
    }
};
