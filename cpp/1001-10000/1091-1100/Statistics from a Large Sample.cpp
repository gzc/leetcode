class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> res{256, -1, 0, 0, 0};
        int n_sample = accumulate(count.begin(), count.end(), 0);
        long sum = 0;
        int nth = (n_sample-1) / 2 + 1;
        int nnth = n_sample % 2 == 1 ? nth : nth + 1;
        
        int n_sample_so_far = 0;
        int mode_samples = 0;
        
        for (int i = 0; i < count.size(); i++) {
            if (count[i] > 0) {
                if (res[0] > 255) {
                    res[0] = i;
                }
                res[1] = i;
                sum += i*count[i];
                if (count[i] > mode_samples) {
                    res[4] = i;
                    mode_samples = count[i];
                }
                
                int previous_sample = n_sample_so_far;
                n_sample_so_far += count[i];
                
                if (nth > previous_sample && nth <= n_sample_so_far) res[3] += i;
                if (nnth > previous_sample && nnth <= n_sample_so_far) res[3] += i;
            }
        }
        
        res[2] = sum*1.0/n_sample;
        res[3] /= 2.0;
        return res;
    }
};
