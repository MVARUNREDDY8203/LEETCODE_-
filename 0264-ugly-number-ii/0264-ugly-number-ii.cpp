class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> ugglies;
        ugglies.insert(1);
        long curr_ugly = 1;
        for (int i=0; i<n; i++) {
            curr_ugly = *ugglies.begin();
            ugglies.erase(ugglies.begin());

            ugglies.insert(curr_ugly * 2);
            ugglies.insert(curr_ugly * 3);
            ugglies.insert(curr_ugly * 5);
        }

        return static_cast<int>(curr_ugly);
    }
};