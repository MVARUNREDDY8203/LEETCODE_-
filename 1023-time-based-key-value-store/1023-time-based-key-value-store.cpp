class TimeMap {
public:
    struct customComparator {
        bool operator() (const int &a, const int &b) const{
            return a >= b;
        }
    };
    unordered_map<string, map<int, string, customComparator>> ump;
    TimeMap() {
       
    }
    
    void set(string key, string value, int timestamp) {
        ump[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (ump.find(key) == ump.end()) return "";
        if (ump[key].find(timestamp) == ump[key].end()) {
            auto it = ump[key].begin();
            for (; it != ump[key].end() && it->first > timestamp; it++) {}
            if (it == ump[key].end()) return "";
            return it->second;
        }
        return ump[key][timestamp];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */