class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.size() < 2) return 0;
        
        int minium = *min_element(num.begin(), num.end());
        int maxium = *max_element(num.begin(), num.end());
        
        int gap = (int)ceil((maxium - minium)*1.0/(num.size()-1));
        int* maxBucket = new int[num.size()];
        int* minBucket = new int[num.size()];
        
        fill(maxBucket, maxBucket+num.size(), INT_MIN);
        fill(minBucket, minBucket+num.size(), INT_MAX);
        
        for(int i = 0;i < num.size();i++)
        {
            int idx = (num[i] - minium)/gap;
            maxBucket[idx] = max(maxBucket[idx], num[i]);
            minBucket[idx] = min(minBucket[idx], num[i]);
        }
        
        int MaxGap = -1;
        int temp = minium;
        for(int i = 0;i < num.size();i++)
        {
            if(maxBucket[i] == INT_MIN)
                continue;
            MaxGap = max(MaxGap, minBucket[i] - temp);
            temp = maxBucket[i];
        }
        return MaxGap;
    }
};