class MKAverage {
    int m;
    int k;
    queue<int> window;
    
    multiset<int> smaller_nums;
    multiset<int> larger_nums;
    multiset<int> middles;
    
    long middles_sum = 0;
    
    void InitializeMultiset() {
        vector<int> nums;
        queue<int> current_window = window;
        while (!current_window.empty()) {
            nums.push_back(current_window.front());
            current_window.pop();
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < m; i++) {
            if (i < k) {
                smaller_nums.insert(nums[i]);
            } else if (i > m - k - 1) {
                larger_nums.insert(nums[i]);
            } else {
                middles_sum += nums[i];
                middles.insert(nums[i]);
            }
        }
    }
public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void AddElement(int val) {
        window.push(val);
        if (middles.empty()) {
            // It only run once.
            if (window.size() == m) {
                InitializeMultiset();
            }
        } else if (val < *smaller_nums.rbegin()) {
            int middle_candidate = *smaller_nums.rbegin();
            smaller_nums.erase(--smaller_nums.end());
            smaller_nums.insert(val);
            middles.insert(middle_candidate);
            middles_sum += middle_candidate;
        } else if (val > *larger_nums.begin()) {
            int middle_candidate = *larger_nums.begin();
            larger_nums.erase(larger_nums.begin());
            larger_nums.insert(val);
            middles.insert(middle_candidate);
            middles_sum += middle_candidate;            
        } else {
            middles.insert(val);
            middles_sum += val;
        }
    }

    void RemoveElement() {
        int val = window.front();
        window.pop();
        if (val <= *smaller_nums.rbegin()) {
            smaller_nums.erase(smaller_nums.lower_bound(val));
            int small_candidate = *middles.begin();
            smaller_nums.insert(small_candidate);
            middles.erase(middles.begin());
            middles_sum -= small_candidate;
        } else if (val >= * larger_nums.begin()) {
            larger_nums.erase(larger_nums.lower_bound(val));
            int large_candidate = *middles.rbegin();
            larger_nums.insert(large_candidate);
            middles.erase(--middles.end());
            middles_sum -= large_candidate;
        } else {
            middles.erase(middles.lower_bound(val));
            middles_sum -= val;
        }
    }

    void addElement(int num) {
        AddElement(num);
        if (window.size() > m) {
            RemoveElement();
        }
    }

    int calculateMKAverage() {
        return window.size() < m ? -1 : middles_sum / middles.size();
    }
};
