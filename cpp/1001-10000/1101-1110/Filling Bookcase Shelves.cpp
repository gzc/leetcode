class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int> dp(books.size()+1, 0);
        
        for (int i = 0; i < books.size(); i++) {
            int minimum_h = 1001*1001;
            int current_shelf_height = -1;
            int n_elements = 0;
            int current_shelf_width = 0;
            for (int j = i; j >= 0; j--) {
                n_elements++;
                current_shelf_width += books[j][0];
                if (current_shelf_width > shelf_width) break;
                current_shelf_height = max(current_shelf_height, books[j][1]);
                minimum_h = min(minimum_h, dp[j] + current_shelf_height);
            }
            
            dp[i+1] = minimum_h;
        } 
        
        return dp.back();
    }
};
