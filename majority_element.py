from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        return nums[len(nums) // 2]
    
    def majorityElement_2(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        count, majority = 0, None
        for n in nums:
            if count == 0:
                count += 1
                majority = n
            elif majority == n:
                count += 1
            else:
                count -= 1
        
        return majority

            

def main():
    sol = Solution()
    nums = [1,1,3,2,2,1,1,1,3]
    x = sol.majorityElement_2(nums)
    print(x)


if __name__ == "__main__":
    main()