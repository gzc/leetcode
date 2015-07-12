class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def searchRange(self, nums, target):
        low = 0
        high = len(nums)-1
        res = []
        
        while low <= high:
            mid = (low+high)/2
            if(nums[mid] < target):
                low = mid+1
            elif(nums[mid] > target):
                high = mid-1
            else:
                bound1 = bound2 = mid
                while bound1 >= 0 and nums[bound1] == nums[mid]:
                    bound1 -= 1
                while bound2 < len(nums) and nums[bound2] == nums[mid]:
                    bound2 += 1
                res.append(bound1+1)
                res.append(bound2-1)
                break
        
        if(len(res) == 0):
            res.append(-1)
            res.append(-1)
            
        return res
