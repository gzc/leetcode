class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i(0),j(citations.size()-1);
        if(citations.size() == 0) return 0;
        
        while(i < j)
        {
            int mid = (i+j) >> 1;
            int citation = citations[mid];
            if(citation >= (citations.size() - mid)) j = mid - 1;
            else i = mid + 1;
        }
        
        if(citations[i] >= citations.size() - i) return citations.size() - i;
        else return citations.size() - i - 1;
    }
    
};