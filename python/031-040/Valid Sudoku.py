class Solution:
    # @param {character[][]} board
    # @return {boolean}
    def isValidSudoku(self, board):
        if not board:
            return False
        
        row, col, box = [[False] * 9 for i in range(9)], [[False] * 9 for i in range(9)], [[False] * 9 for i in range(9)]
        
        for i in range(9):
            for j in range(9):
                num = board[i][j]
                if num != '.':
                    index = int(num) - 1
                    k = i / 3 * 3 + j / 3
                    if row[i][index] or col[j][index] or box[k][index]:
                        return False
                    
                    row[i][index] = col[j][index] = box[k][index] = True
        
    return True