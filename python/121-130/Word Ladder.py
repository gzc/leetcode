class Solution:
    # @param {string} beginWord
    # @param {string} endWord
    # @param {set<string>} wordDict
    # @return {integer}
    def ladderLength(self, beginWord, endWord, wordDict):
        dis = {}
        dis[beginWord] = 1
        chars = string.ascii_lowercase
        myqueue = [beginWord]
        
        while len(myqueue) > 0:
            word = myqueue[0]
            del myqueue[0]
            if word == endWord:
                break
            for i in range(len(word)):
                for c in chars:
                    newWord = word[:i] + c + word[i+1:]
                    if newWord in wordDict and newWord not in dis:
                        dis[newWord] = dis[word]+1
                        myqueue.append(newWord)
    
        if endWord not in dis:
            return 0
return dis[endWord]