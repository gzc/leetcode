class Solution(object):
    def getPermutation(self, n, k):
        """
            :type n: int
            :type k: int
            :rtype: str
            """
        numset = ['1','2','3','4','5','6','7','8','9']
        pTable = [1]*10
        for i in range(1,10):
            pTable[i] = i * pTable[i-1]
        
        res = ''
        while n > 0:
            temp = (k-1)/pTable[n-1]
            res += numset[temp]
            del numset[temp]
            k -= temp * pTable[n-1]
            n -= 1
        
        return res