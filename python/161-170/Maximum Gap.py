import math

class Solution:
    # @param num, a list of integer
    # @return an integer
    def maximumGap(self, num):
        if len(num) < 2 or min(num) == max(num):
            return 0
        a, b = min(num), max(num)
        gap = int(math.ceil((b-a)*1.0/(len(num)-1)))
        bucket = [[None, None] for _ in range((b-a)/gap+1)]
        for n in num:
            b = bucket[int((n-a)/gap)]
            b[0] = n if b[0] is None else min(b[0], n)
            b[1] = n if b[1] is None else max(b[1], n)
        bucket = [b for b in bucket if b[0] is not None]
        return max(bucket[i][0]-bucket[i-1][1] for i in range(1, len(bucket)))

items = [1,1,1,1,1,5,5,5,5,5]
s = Solution()
print s.maximumGap(items)