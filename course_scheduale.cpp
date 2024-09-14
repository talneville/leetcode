/*

____________________COURSE_SCHEDUALE____________________

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] 
indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. 
So it is impossible.


*/


#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class Solution_s {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 0) {
            return false;
        }
        if (numCourses == 1) {
            return true;
        }

        vector<list<int>> graph = vector<list<int>>(numCourses);
        vector<int> in_degree = vector<int>(numCourses, 0);
        list<int> source;
        int order = 0;

        for (vector<int> it : prerequisites) {
            graph[it[1]].push_back(it[0]);
            in_degree[it[0]]++;
        }

        for (int i = 0; i < in_degree.size(); i++) {
            if (in_degree[i] == 0) {
                source.push_back(i);
            }
        }
        
        if (source.empty() == true) {
            return false;
        }

        while (source.empty() == false) {
            int current_source = source.front();
            source.pop_front();
            order++;

            for (int neighbours : graph[current_source]) {
                in_degree[neighbours]--;
                if (in_degree[neighbours] == 0) {
                    source.push_back(neighbours);
                }
            }
            graph[current_source].clear();
        }

        if (order == numCourses) {
            return true;
        }
        return false;
    }
};




/*

____________________COURSE_SCHEDUALE_II___________________

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. 
If there are many valid answers, return any of them. 
If it is impossible to finish all courses, return an empty array.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:
Input: numCourses = 1, prerequisites = []
Output: [0]


*/


#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 0) {
            return vector<int>();
        }
        if (numCourses == 1) {
            return vector<int>(1, 0);
        }

        vector<list<int>> graph = vector<list<int>>(numCourses);
        vector<int> in_degree = vector<int>(numCourses, 0);
        list<int> source;
        int order = 0;
        vector<int> result;

        for (vector<int> it : prerequisites) {
            graph[it[1]].push_back(it[0]);
            in_degree[it[0]]++;
        }

        for (int i = 0; i < in_degree.size(); i++) {
            if (in_degree[i] == 0) {
                source.push_back(i);
            }
        }

        if (source.empty() == true) {
            return vector<int>();
        }

        while (source.empty() == false) {
            int current_source = source.front();
            source.pop_front();
            order++;

            for (int neighbours : graph[current_source]) {
                in_degree[neighbours]--;
                if (in_degree[neighbours] == 0) {
                    source.push_back(neighbours);
                }
            }
            graph[current_source].clear();
            result.push_back(current_source);
        }

        if (order == numCourses) {
            return result;
        }
        return vector<int>();
    }
};



int main() {
    vector<vector<int>> prerequisites = vector<vector<int>>(1, { 1, 0 });
    Solution sol;
    sol.findOrder(2, prerequisites);
    return 0;
}