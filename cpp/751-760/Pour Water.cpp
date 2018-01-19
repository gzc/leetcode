class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for (int i = 0; i < V; i++) {
            // try left
            int candidateHeight = heights[K];
            int candidateIndex = K;
            
            int j = K - 1;
            while(j >= 0 && heights[j] <= candidateHeight) {
                if (heights[j] < candidateHeight) {
                    candidateHeight = heights[j];
                    candidateIndex = j;
                }
                j--;
            }
            
            // try right
            if (candidateIndex == K) {
                j = K + 1;
                while(j < heights.size() && heights[j] <= candidateHeight) {
                    if (heights[j] < candidateHeight) {
                        candidateHeight = heights[j];
                        candidateIndex = j;
                    }
                    j++;
                }
            }
            
            heights[candidateIndex]++;
        }
        
        return heights;
    }
};
