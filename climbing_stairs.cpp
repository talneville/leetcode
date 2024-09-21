/*

___________________________________CLIMBING_STAIRS___________________________________

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?


Example 1:
	Input: n = 2
	Output: 2
	Explanation: There are two ways to climb to the top.
			     1. 1 step + 1 step
				 2. 2 steps

Example 2:
	Input: n = 3
	Output: 3
	Explanation: There are three ways to climb to the top.
				 1. 1 step + 1 step + 1 step
				 2. 1 step + 2 steps
				 3. 2 steps + 1 step


Constraints:
	1 <= n <= 45

*/




#include <vector>

using namespace std;


class Solution {
public:
    int climbStairs_AUX(int n, vector<int>& map) {
        if ((n == 1) || (n == 2) || (map[n - 1] != 0)) {
            return map[n - 1];
        }

        int x = climbStairs_AUX(n - 1, map) + climbStairs_AUX(n - 2, map);
        map[n - 1] = x;
        return x;
    }

    int climbStairs(int n) {
        vector<int> map = vector<int>(n, 0);
        if (map.empty()) {
            return 0;
        }
        if (map.size() == 1) {
            return 1;
        }
        map[0] = 1;
        map[1] = 2;
        return climbStairs_AUX(n, map);
    }
};