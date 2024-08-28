class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int l = INT_MAX, r = INT_MIN, n = time.size();
        for (int i=0; i<n; i++) {
            if (time[i] > r) {
                r = time[i];
            }
        }
        l = 1;
        r = r * totalTrips;
        while (l < r) {
            long long int mid = l + (r - l)/2;
            long long int cnt = 0;
            for (int i=0; i<n; i++) {
                // check if at mid no of days, all buses have atleast totalTrips trips
                // each bus will have mid / time[i] no of trips completed at mid no of days
                cnt += mid / time[i];
                // if (cnt >= totalTrips) break;
            }
            if (cnt >= totalTrips) {
                r = mid;
            }
            else l = mid + 1;
            
            cout<<l<<" "<<mid<<" "<<r<<endl;
        }
        return l;
    }
};