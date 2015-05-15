class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        vector<int> last;
        if (rowIndex < 0) return result;        

        for(int i = 0; i <= rowIndex; i++) {
            vector<int> row(i+1, 1);

            for(int j = 1; j < i; j++) 
                row[j] = last[j-1] + last[j];

            if(i == rowIndex) return row;
            last = row;
        }
    }
};
