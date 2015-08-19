class Solution:
    # @param {character[][]} matrix
    # @return {integer}
    def maximalSquare(self, matrix):
        if len(matrix) == 0:
            return 0
        h = [0] * (len(matrix[0])+1)
        res = 0
        
        for i in range(len(matrix)):
            matrix[i].append('0')
            mystack = []
            
            for j in range(len(matrix[i])):
                if matrix[i][j] == '1':
                    h[j] += 1
                else:
                    h[j] = 0
                
                if len(mystack) == 0 or h[j] >= h[mystack[-1]]:
                    mystack.append(j)
                else:
                    while len(mystack) > 0 and h[j] < h[mystack[-1]]:
                        height = h[mystack[-1]]
                        del mystack[-1]
                        width = j if len(mystack) == 0 else j - 1 - mystack[-1]
                        side = min(height, width)
                        res = max(res, side*side)
                    mystack.append(j)
        
        return res