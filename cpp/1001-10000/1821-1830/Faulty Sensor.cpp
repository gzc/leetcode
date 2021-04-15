class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        int n = sensor1.size();
        for (int i = 0; i < n - 1; i++) {
            if (sensor1[i] == sensor2[i]) {
                continue;
            }
            
            bool is_sensor_1 = true;
            for (int j = i; j < n - 1; j++) {
                if (sensor1[j] != sensor2[j+1]) {
                    is_sensor_1 = false;
                    break;
                }
            }
            if (is_sensor_1) return 1;
            
            bool is_sensor_2 = true;
            for (int j = i; j < n - 1; j++) {
                if (sensor1[j+1] != sensor2[j]) {
                    is_sensor_2 = false;
                    break;
                }
            }
            if (is_sensor_2) return 2;
        }
        return -1;
    }
};
