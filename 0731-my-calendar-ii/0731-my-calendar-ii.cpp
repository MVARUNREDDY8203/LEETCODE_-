class MyCalendarTwo {
public:
    vector<pair<int, int>> non_overlapping;
    vector<pair<int, int>> overlapping;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (int i=0; i<overlapping.size(); i++) {
            if (max(start, overlapping[i].first) <= min(end-1, overlapping[i].second)) return false;
        }

        for (int i=0; i<non_overlapping.size(); i++) {
            if (max(start, non_overlapping[i].first) <= min(end-1, non_overlapping[i].second)) {
                overlapping.push_back({max(start, non_overlapping[i].first), min(end-1, non_overlapping[i].second)});
            }
        }

        non_overlapping.push_back({start, end-1});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */