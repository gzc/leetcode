class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result(asteroids.size());
        int size = 0;
        
        for (int i = 0; i < asteroids.size(); i++) {
            if (size == 0 || asteroids[i] > 0) {
                result[size] = asteroids[i];
                size++;
                continue;
            }
            if (asteroids[i] <= 0) {
                while (size > 0) {
                    if (result[size-1] < 0) {
                        result[size] = asteroids[i];
                        size++;
                        break;
                    } else {
                        if (abs(asteroids[i]) > result[size-1]) {
                            size--;
                        } else if (abs(asteroids[i]) == result[size-1]) {
                            size--;
                            break;
                        } else {
                            break;
                        }
                        
                        if (size == 0) {
                            result[size] = asteroids[i];
                            size++;
                            break;
                        }
                    }
                }
            }
        }
        
        result.resize(size);
        return result;
    }
};
