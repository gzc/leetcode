class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        unordered_map<int, int> umap;
        int num = 0, n = sentence.size();
        for (int i = 0; i < rows; i++){
            int start = num % n;
            if (umap.count(start) == 0){
                int cnt = 0, len = 0;
                for (int i = start; len < cols; i = (i+1) % n, cnt++) {
                    if (len + sentence[i].size() > cols)
                        break;
                    len += sentence[i].size() + 1;
                }
                umap[start] = cnt;
            }
            num += umap[start];
        }
        return num / n;
    }
};
