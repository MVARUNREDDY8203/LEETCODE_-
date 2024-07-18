class MyCalendar {
public:
    vector<pair<int, int>> cal;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        // sort(cal.begin(), cal.end(), [](const pair<int, int> &a, const pair<int, int> &b) {return a.first < b.first;});
        // for (auto i: cal) cout<<" ["<<i.first<<" "<<i.second<<"], ";
        // cout<<endl;
        for (int i=0; i<cal.size(); i++) {

            if (start >= cal[i].first && start < cal[i].second) return false;
            if (end > cal[i].first && end <= cal[i].second) return false;

            if (cal[i].first >= start && cal[i].first < end) return false;
            if (cal[i].second > start && cal[i].second <= end) return false;
        }
        cal.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */