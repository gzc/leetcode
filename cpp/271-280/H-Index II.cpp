class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = citations.size();
        
        int i = 0;
        for(int i = 0;i < citations.size();i++)
        {
            if(citations[i] >= h)
                break;
            h--;
        }
        
        return h;
    }
};