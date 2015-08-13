class Solution:
    # @param {integer[]} ratings
    # @return {integer}
    def candy(self, ratings):
        l = len(ratings)
        p = [1]*l
        
        for i in range(l-1):
            if ratings[i+1] > ratings[i]:
                p[i+1] = p[i]+1
        for i in range(l-1, 0, -1):
            if ratings[i-1] > ratings[i]:
                p[i-1] = max(p[i-1], p[i]+1)
        
        return sum(p)