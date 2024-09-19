/*

__________________________________________POT_HOLES__________________________________________


There are N potholes on a straight road parallel to the y-axis. 
The positions of the potholes are described by two arrays of integers, X and Y. 
The K-th pothole (for K within the range [0..N-1]) is located at coordinates (X[K], Y[K]).

In order to fix the potholes, a road roller of width W will be used. 
The road roller can only drive along the street (parallel to the y-axis). 
It can start driving from any x coordinate at the beginning of the road (a point whose y coordinate is equal to 0). 
During one drive, for a chosen starting point (x, 0) of the road roller’s left end,
the road roller drives upwards and patches all potholes on its way that fall within the width of the road roller, W,
and are to the right of its starting position, x. 
In other words, it patches all the potholes whose first coordinate is between x and x+W inclusive.

What is the minimum number of road roller drives required to patch all the potholes?

Write a function:
    class Solution {
        public int solution(int[] X, int[] Y, int W);
    }

that, given two arrays of integers X and Y, describing the positions of the N potholes, and an integer W, 
specifying the width of the road roller, returns the minimum number of drives needed to patch all the potholes.


Example 1:
    Given X = [2, 4, 2, 6, 7, 1], Y = [0, 5, 3, 2, 1, 5] and W = 2, the answer is 3.
    At least three drives will be needed to patch all the potholes. 
    For example, the drives could start respectively at points (1, 0), (4, 0) and (6, 0). 
    During the first drive, the road roller would patch the potholes located at (2, 0), (2, 3) and (1, 5). 
    During the second drive, the potholes located at (4, 5) and (6, 2) would be patched. 
    Finally, in the third drive, the pothole located at (7, 1) would be patched.

Example 2:
    Given X = [4, 8, 2, 2, 1, 4], Y = [1, 2, 3, 1, 2, 3] and W = 3, the answer is 2. 
    If the first drive of the road roller started at point (1, 0) and the second drive at the point (6, 0), 
    all the potholes would be patched.

Example 3:
    Given X = [0, 3, 6, 5], Y = [0, 3, 2, 4] and W = 1, the answer is 3. 
    The first drive of the road roller could start at point (0, 0), the second drive at point (3, 0) and the third at point (5, 0).

Write an efficient algorithm for the follwing assumptions:
    - N is an integer within the range [1,...,100000].
    - Each element of arrays X and Y is an integer withing the rang [0,...,1000000000].
    - W is an integer withing the rang [0,...,1000000000].

*/

#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> removeDuplicates(vector<pair<int, int>> array) {
        vector<pair<int, int>> result;
        result.push_back(array[0]);

        for (int i = 1; i < array.size(); i++) {
            if (array[i] != array[i - 1]) {
                result.push_back(array[i]);
            }
        }
        return result;
    }

    int solution(vector<int> X, vector<int> Y, int width) {
        if (X.size() != Y.size()) {
            return 0;
        }
        
        vector<pair<int, int>> coordinates;

        for (int i = 0; i < X.size(); i++) {
            coordinates.push_back({ X[i], Y[i] });
        }
        sort(coordinates.begin(), coordinates.end());

        coordinates = removeDuplicates(coordinates);
        
        float result = coordinates.size() / width;
        return ceil(result);
    }
};




/*_______________________________CHAT_GPT_IMPROVEMENTS_______________________________*/

class Solution {
public:
    int solution(vector<int> X, vector<int> Y, int width) {
        if (X.empty()) return 0;

        // Create pairs of coordinates
        vector<pair<int, int>> coordinates;
        for (int i = 0; i < X.size(); i++) {
            coordinates.push_back({ X[i], Y[i] });
        }

        // Sort by the X coordinate (y doesn't matter for this problem)
        sort(coordinates.begin(), coordinates.end());

        int drives = 0;
        int current_coverage = -1;

        // Greedily cover potholes
        for (int i = 0; i < coordinates.size(); i++) {
            if (coordinates[i].first > current_coverage) {
                // Start a new drive
                drives++;
                current_coverage = coordinates[i].first + width;
            }
        }

        return drives;
    }
};
