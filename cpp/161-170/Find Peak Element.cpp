class Solution {
public:
    int findPeakElement(const vector<int> &num) 
    {
        int low(0), high(num.size()-1);
        
        while(low < high)
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            num[mid1] < num[mid2] ?  low = mid2 : high = mid1;
        }
        return low;
    }
};
