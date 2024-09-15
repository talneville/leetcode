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