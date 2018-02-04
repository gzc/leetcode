class Solution {
    
private:
    int count;
   
    void merge(vector<int>& nums, int start, int mid, int end){
        int l = start, r = mid + 1;
        while(l <= mid && r <= end){
            if((long)nums[l] > (long) 2 * nums[r]){
                count += (mid - l + 1);
                r++;
            } else{
                l++;
            }
        }
        sort(nums.begin() + start, nums.begin() + end + 1);
    }
    
    void mergeSort(vector<int>& nums, int start, int end){
        if(start == end) return;
        
        int mid = (start + end)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, start, mid, end);
    }
    
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        count = 0;
        mergeSort(nums, 0, nums.size()-1);
        return count;
    }
};
