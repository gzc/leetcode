class NumArray {
    int *a;
public:
    NumArray(vector<int> &nums) {
        a = new int[nums.size()+1];
        a[0] = 0;
        for(int i = 0;i < nums.size();i++) {
            a[i+1] = nums[i] + a[i];
        }
    }

    int sumRange(int i, int j) {
        return a[j+1] - a[i];
    }
};
