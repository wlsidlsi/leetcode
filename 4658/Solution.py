Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
#Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
#
#Example 2:
#
#Input: nums = [1,1,1,1,1]
#Output: [1,2,3,4,5]
#Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
#
#Example 3:
#
#Input: nums = [3,1,2,10,1]
#Output: [3,4,6,16,17]
#
# 
#
#Constraints:
#
#    1 <= nums.length <= 1000
#    -10^6 <= nums[i] <= 10^6


class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        def runningSum1(nums: List[int]) -> List[int]:
            list_sums = [nums[0]]        
            for element in range(1, len(nums)):
                list_sums.append(nums[element] + list_sums[ element - 1])
            return list_sums

        def runningSum2(nums: List[int]) -> List[int]:
            # create a shallow copy
            sums = nums[:]
            
            # use while instead of for loop with range
            index = 1 
            while index < len(nums):
                sums[index] += sums[ index - 1]
                index += 1
            return sums

        return runningSum2(nums)
