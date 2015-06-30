# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    dict = {}
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if not node:
            return None
        
        if node not in self.dict:
            self.dict[node] = UndirectedGraphNode(node.label)
            for e in node.neighbors:
                self.dict[node].neighbors.append(self.cloneGraph(e))

    return self.dict[node]