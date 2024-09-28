""""

_________________________________HAPPY_NUMBER_________________________________

Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.


Example 1:
    Input: n = 19
    Output: true
    Explanation:
    1^2 + 9^2 = 82
    8^2 + 2^2 = 68
    6^2 + 8^2 = 100
    1^2 + 0^2 + 0^2 = 1

Example 2:
    Input: n = 2
    Output: false
 

Constraints:
    1 <= n <= 231 - 1

    
def createNumber(self, n: int) -> int: 
Calculate the sum of squares of the digits of n

"""

class Solution:
    def createNumber(self, n: int) -> int:
        sum = 0

        while n > 0:
            digit = n % 10
            sum += digit * digit 
            temp //= 10   

        return sum

    def isHappy(self, n: int) -> bool:
        if n == 1:
            return True
        
        # Using Floyd's Cycle-Finding Algorithm to detect a cycle
        slow = n
        fast = self.createNumber(n)

        while fast != 1 and slow != fast:
            slow = self.createNumber(slow)               # Move slow one step
            fast = self.createNumber(self.createNumber(fast))  # Move fast two steps

        # If fast reaches 1, n is a happy number
        # If the loop terminates because slow == fast, then the following will return False
        return fast == 1
    