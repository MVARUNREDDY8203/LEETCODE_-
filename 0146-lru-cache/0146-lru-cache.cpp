class LRUCache {
public:
    struct kvp{
        int key;
        int val;
        kvp(int k, int v){
            key = k;
            val = v;
        }
    };
    list<kvp> dll;
    list<kvp> :: iterator itx = dll.begin();
    unordered_map<int, list<kvp>:: iterator> ump;
    int size = 0;
    int temp_key = 0;
    int temp_val = 0;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (ump.find(key) == ump.end()) return -1;

        int temp_val = ump[key]->val;
        dll.erase(ump[key]);
        dll.push_front(kvp(key, temp_val));
        ump[key] = dll.begin();

        return ump[key]->val;
    }
    
    void put(int key, int value) {
        if(ump.find(key) != ump.end()){
            itx = ump[key];
            dll.erase(itx);
            ump.erase(key);
        }
        if(ump.size() >= size) {
            itx = dll.end();
            --itx;
            temp_key = itx->key;
            ump.erase(temp_key);
            dll.pop_back();
        }
        dll.push_front(kvp(key, value));
        ump[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */