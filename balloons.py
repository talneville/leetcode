"""
________________________________MINIMUM_NUMBER_OF_ARROWS_TO_BURST_BALLOONS________________________________

There are some spherical balloons taped onto a flat wall that represents the XY-plane.
The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes 
a balloon whose horizontal diameter stretches between xstart and xend. 
You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. 
A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. 
There is no limit to the number of arrows that can be shot.
A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.


Example 1:
    Input: points = [[10,16],[2,8],[1,6],[7,12]]
    Output: 2
    Explanation: The balloons can be burst by 2 arrows:
                - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
                - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

Example 2:
    Input: points = [[1,2],[3,4],[5,6],[7,8]]
    Output: 4
    Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.

Example 3:
    Input: points = [[1,2],[2,3],[3,4],[4,5]]
    Output: 2
    Explanation: The balloons can be burst by 2 arrows:
                - Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
                - Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
    

Constraints:
    1 <= points.length <= 105
    points[i].length == 2
    -2^31 <= xstart < xend <= 2^31 - 1


"""

from typing import List

class Solution:
    # this function assumes that two interval intersect
    def mergeIntersect(self, point_1: List[int], point_2: List[int]) -> List[int]:
        res = [max(point_1[0], point_2[0]), min(point_1[1], point_2[1])]
        return res



    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if len(points) == 0:
            return 0
        
        # sort via the first element in list
        # equivilant to  points.sort()
        points.sort(key=lambda x: (x[0], x[1]))
        count = len(points)
        
        prev = points[0]
        for i in range(1, len(points)):            
            current = points[i]
            if(current[0] <= prev[1]):
                prev = self.mergeIntersect(prev, current)
                count -= 1
            else:
                prev = current

        return count

