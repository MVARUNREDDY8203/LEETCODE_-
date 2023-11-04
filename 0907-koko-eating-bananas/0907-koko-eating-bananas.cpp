class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_val = -1;
        for (auto i: piles) max_val = max(max_val, i);
        int l = 1, r = max_val;
        while (r - l >= 10) {
            int mid = (l+r)/2;
            long long int time = 0;
            for (int j=0; j<piles.size(); j++) {
                time += ceil(piles[j] / (double)mid);
            }
            // cout<<l<<" "<<mid<<" "<<r<<endl;
            if (time > h) l = mid;
            else r = mid;
        }
        for (int i=l; i<=r; i++) {
            long long int time = 0;
            for (int j=0; j<piles.size(); j++) {
                time += ceil(piles[j] / (double)i);
            }
            if (time <= h) return i;
        }
        return l;
    }
};
/*
given :
- array piles with piles[i] bananas;
- h hrs
- k bananas/hr
- 1 hr choices only
- 
*/