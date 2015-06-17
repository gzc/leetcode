class Solution:
    # @param {string} s
    # @return {boolean}
    def isNumber(self, s):
        try:
            num = float(s.strip())
            return True
        except:
            return False
