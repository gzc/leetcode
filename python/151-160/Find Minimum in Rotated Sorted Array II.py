class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def findMin(self, nums):
        start = 0
        end = len(nums)-1
        
        while start < end:
            if nums[start] < nums[end]:
                return nums[start]
            
            mid = (start+end)/2
            if(nums[mid] > nums[start]):
                start = mid+1
            elif(nums[mid] < nums[start]):
                end = mid
            else:
                start += 1

    return nums[start]