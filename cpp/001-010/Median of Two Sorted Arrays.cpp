class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2 == 1) {
            return findKthElement((m + n) / 2 + 1, nums1, 0, nums2, 0);
        } else {
            return (findKthElement((m + n) / 2, nums1, 0 ,nums2, 0) + findKthElement((m + n) / 2 + 1, nums1, 0 ,nums2, 0)) / 2;
        }
    }
    
    double findKthElement(int k, const vector<int>& nums1, int idx1, const vector<int>& nums2, int idx2) {
        int l1 = nums1.size() - idx1;
        int l2 = nums2.size() - idx2;
        if (l1 > l2) {
            return findKthElement(k, nums2, idx2, nums1, idx1);
        }
        if (l1 == 0) {
            return nums2[idx2 + k - 1];
        }
        if (k == 1) {
            return min(nums1[idx1], nums2[idx2]);
        }
        int cut1 = min(k/2, l1);
        int cut2 = k - cut1;
        if (nums1[idx1 + cut1 - 1] > nums2[idx2 + cut2 - 1]) {
            return findKthElement(k - cut2, nums1, idx1, nums2, idx2 + cut2);
        } else {
            return findKthElement(k - cut1, nums1, idx1 + cut1, nums2, idx2);
        }
    }
};
