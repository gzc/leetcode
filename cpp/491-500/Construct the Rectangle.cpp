class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> output(2);
	
	    output[0] = 1;
	    output[1] = area;
	    int length = 0;
	
        for (int width = 1; width <= (int)sqrt(area); width++) {
        
            length = area/width;
        
            if ((length * width) == area && abs(length - width) <= abs(output[0] - output[1])) {
        	    output[0] = length;
        	    output[1] = width;
            }
        }
        
        return output;
    }
};
