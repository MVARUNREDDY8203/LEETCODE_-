class MyCalendar {
public:
    vector<pair<int, int>> booklet;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for (int i=0; i<booklet.size(); i++) {
            if (booklet[i].first <= start && start <= booklet[i].second) return false;
            if (booklet[i].first <= end-1 && end-1 <= booklet[i].second) return false;
            if (start <= booklet[i].first && booklet[i].second <= end-1) return false;
        }
        booklet.push_back({start, end-1});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */