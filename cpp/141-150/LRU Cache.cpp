struct My_node {
    int key, value;
    My_node(int k ,int v) : key(k),value(v) {}
};

class LRUCache{
    
    int capacity;
    typedef list<My_node> mylist;
    typedef unordered_map<int, mylist::iterator> mymap;
    mylist lists;
    mymap maps;
    
    void MoveToFront(mylist::iterator it)
    {
        lists.emplace_front(*it);
        maps[it->key] = lists.begin();
        lists.erase(it);
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        maps.reserve(capacity);
    }
    
    int get(int key) {
        mymap::iterator it = maps.find(key);
        if(it == maps.end()){
            return -1;
        }
        mylist::iterator node = it->second;
        MoveToFront(node);
        return node->value;
    }
    
    void set(int key, int value) {
        mymap::iterator it = maps.find(key);
        if(it != maps.end()){
            mylist::iterator list_it = it->second;
            list_it->value = value;
            MoveToFront(list_it);
            return;
        }
        
        if(lists.size() == capacity)
        {
            My_node node = lists.back();
            maps.erase(node.key);
            lists.pop_back();
        }
        
        My_node node(key,value);
        lists.emplace_front(node);
        maps[key] = lists.begin();

    }
    
};
