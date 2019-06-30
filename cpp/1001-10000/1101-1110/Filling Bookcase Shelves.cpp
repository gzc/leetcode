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

class Solution {
public:
    int dfs(vector<vector<int>>& books, int shelf_width, int ind, int remain_width, int current_height, map<pair<int, int>, int>& cache) {
        if (ind == books.size()) {
            return current_height;
        }
        auto it = cache.find({ind, remain_width});
        if (it != cache.end()) return it->second;
        
        // 1) we can put current book on a new shelf.
        int minimum_height = INT_MAX;
        minimum_height = current_height + dfs(books, shelf_width, ind+1, shelf_width - books[ind][0], books[ind][1], cache);
        // 2) If we have plenty width in current shelf, we can also put in current shelf.
        if (books[ind][0] <= remain_width) {
            current_height = max(current_height, books[ind][1]);
            minimum_height = min(minimum_height, dfs(books, shelf_width, ind+1, remain_width - books[ind][0], current_height, cache));
        }
        return cache[{ind, remain_width}] = minimum_height;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        map<pair<int, int>, int> cache; // {ith_book}, {how many width remained in current shelf}
        // This cache means when I process ith book and in a w position, how many remain minimum height I need for remaining books in that state.
        return dfs(books, shelf_width, 0, shelf_width, 0, cache);
    }
};
