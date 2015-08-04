class Solution:
    
    def help(self, board, i, j, rows, cols, rec):
        if i == 9:
            return True
        
        nexti = nextj = 0
        if j != 8:
            nexti = i
            nextj = j + 1
        else:
            nexti = i + 1
        
        if board[i][j] != '.':
            return self.help(board, nexti, nextj, rows, cols, rec)
        else:
            t = (i/3)*3+j/3
            for k in range(9):
                if rows[i][k] == False and cols[k][j] == False and rec[t][k] == False:
                    rows[i][k] = cols[k][j] = rec[t][k] = True
                    board[i][j] = chr(49+k)
                    check = self.help(board, nexti, nextj, rows, cols, rec)
                    if check:
                        return True
                    rows[i][k] = cols[k][j] = rec[t][k] = False
                    board[i][j] = '.'
        return False
    
    
    # @param {character[][]} board
    # @return {void} Do not return anything, modify board in-place instead.
    def solveSudoku(self, board):
        rows, cols, rec = [[False] * 9 for i in range(9)], [[False] * 9 for i in range(9)], [[False] * 9 for i in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    index = int(board[i][j]) - 1
                    k = (i/3)*3 + j/3
                    rows[i][index] = cols[index][j] = rec[k][index] = True
        self.help(board, 0, 0, rows, cols, rec)