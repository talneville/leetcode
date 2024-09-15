/*

__________________PERMUTATIONS__________________

Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

*/


#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return vector<vector<int>>(1, vector<int>());
        }
        if (nums.size() == 1) {
            return vector<vector<int>>(1, vector<int>(1, nums[0]));
        }
        
        vector<vector<int>> permutataions;
        vector<vector<int>> result;

        if (nums.size() == 2) {
            permutataions.push_back({ nums[0], nums[1] });
            permutataions.push_back({ nums[1], nums[0] });
            return permutataions;
        }

        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            nums.erase(nums.begin() + i);
            permutataions = permute(nums);
            for (int j = 0; j < permutataions.size(); j++) {
                permutataions[j].insert(permutataions[j].begin(), first);
            }
            result.insert(result.end(), permutataions.begin(), permutataions.end());
            nums.insert(nums.begin() + i, first);
        }
        return result;       
    }
};


/*

CHAT_GPT_SOLUTION

The difference between the two solutions lies in how they handle placing elements at the beginning of each permutation.

First Solution: In the first solution, nums[i] is removed from the array, and the rest of the elements are permuted.
After generating all the permutations of the remaining elements, nums[i] is added back to the front of each permutation. 
This ensures that nums[i] is the first element in all the generated permutations for that iteration.

Second Solution: In the second solution, instead of removing nums[i], it is swapped with the element at the first position.
Then, the rest of the array (starting from the second element) is permuted. 
This also results in nums[i] being the first element of the permutations. 
However, rather than removing and reinserting, the swapping technique achieves the same effect more directly.

In both approaches, nums[i] is made the first element of the permutations, but the second solution uses swapping 
instead of removing and re-inserting, which is more efficient in terms of array manipulation.

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);  // Add current permutation to the result
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);      // Swap to create a new permutation
            backtrack(nums, start + 1, result);  // Recurse for the next element
            swap(nums[start], nums[i]);      // Backtrack to restore original order
        }
    }
};
