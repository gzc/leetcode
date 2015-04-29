class Solution {
    
    vector<int> help(vector<string> &words, int start, int end, int L)
    {
        int wordCount = end - start;
        if(words.size() == end) return vector<int>(wordCount-1,1);
        int sum = L;
        for(int i = start;i < end;i++)
            sum -= words[i].length();
        int Count = wordCount - 1;
        
        int average = sum / Count;
        vector<int> blocks(wordCount-1, average);
        sum -= average * Count;
        
        int index = 0;
        while(sum--)
            blocks[index++]++;
        
        return blocks;
    }
    
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        if(words.size() == 0) return result;
        int from = 0;
        
        
        while(from < words.size())
        {
            string temp(L, ' ');
            
            int start = from;
            int len = words[from].length();
            while(len <= L && from < words.size()){
                from ++;
                if(from == words.size()) break;
                len = len + words[from].length() + 1;
            }
            
            if(from - start == 1){
                for(int n = 0;n < words[start].length();n++)
                    temp[n] = words[start][n];
            } else {
                vector<int> blocks = help(words, start, from, L);
                int index = 0;
                int skip = 0;
                for(int i = start;i < from;i++)
                {
                    string now = words[i];
                    for(int j = 0;j < now.length();j++)
                        temp[index++] = now[j];
                    index += blocks[skip++];
                }
            }
            
            result.push_back(temp);
        }
        
        return result;
    }
};
