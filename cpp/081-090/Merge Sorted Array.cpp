class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i = m-1;i >= 0;i--)
            nums1[n+i] = nums1[i];
            
        int i(0),j(0),k(0);
        
        while(i < n && j < m)
        {
            if(nums1[j+n] < nums2[i])
            {
                nums1[k] = nums1[j+n];
                j++;
            }
            else
            {
                nums1[k] = nums2[i];
                i++;
            }
            if(i == n) return;
            k++;
        }
        
        while(i < n)
            nums1[k++] = nums2[i++];
    }
};
