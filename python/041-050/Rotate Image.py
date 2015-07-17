class Solution:
    # @param {integer[][]} matrix
    # @return {void} Do not return anything, modify matrix in-place instead.
    def rotate(self, matrix):
        n = len(matrix)-1
        i = 0
        while i <= n -i:
            j = i
            while j <= n - i - 1:
                tmp = matrix[j][n-i]
                matrix[j][n-i] = matrix[i][j]
                matrix[i][j] = matrix[n-j][i]
                matrix[n-j][i] = matrix[n-i][n-j]
                matrix[n-i][n-j] = tmp
                j += 1
            i += 1