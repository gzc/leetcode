class Vector2D {
    
    int j;
    vector<vector<int>>::iterator i, iEnd;
    
public:
    Vector2D(vector<vector<int>>& vec2d) {
        j = 0;
        i = vec2d.begin();
        iEnd = vec2d.end();
    }
    
    int next() {
        hasNext();
        return (*i)[j++];
    }
    
    bool hasNext() {
        while (i != iEnd && j == (*i).size())
            i++, j = 0;
        return i != iEnd;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */