class SnakeGame {
    
    queue<pair<int, int>> myqueue;
    set<pair<int, int>> myset;
    vector<pair<int, int>> food;
    
    int width;
    int height;
    int idx;
    
    int curi,curj;
    int score;
    
    
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        myqueue.push(make_pair(0,0));
        myset.insert(make_pair(0,0));
        this->width = width;
        this->height = height;
        this->food = food;
        this->idx = 0;
        curi = curj = 0;
        score = 0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int move_row = 0;
        int move_col = 0;
        if(direction == "U") {
            move_row = -1;
        } else if(direction == "D") {
            move_row = 1;
        } else if(direction == "L") {
            move_col = -1;
        } else if(direction == "R") {
            move_col = 1;
        }
        
        int nexti = curi + move_row;
        int nextj = curj + move_col;
        if (nexti < 0 || nexti >= height || nextj < 0 || nextj >= width) return -1;
        pair<int, int> head = make_pair(nexti, nextj);
        
        myqueue.push(head);
        if (food[idx] == head) {
            myset.insert(head);
            ++score;
            ++idx;
        } else {
            pair<int, int> tail = myqueue.front();
            myqueue.pop();
            myset.erase(tail);
            if (myset.count(head) > 0) return -1;
            myset.insert(head);
        }
        
        curi = nexti;
        curj = nextj;
        
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
