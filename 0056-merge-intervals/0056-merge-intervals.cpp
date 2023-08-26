class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end());
        int cs = intervals[0][0];
        int ce = intervals[0][1];

        int i=0;
        for(i=0; i<intervals.size()-1; i++){
            if(intervals[i+1][0] <= ce){
                cs = min(cs, intervals[i+1][0]);
                ce = max(ce, intervals[i+1][1]);
            }else{
                ans.push_back({cs, ce});
                cs = intervals[i+1][0];
                ce = intervals[i+1][1];
            }
        }
        ans.push_back({cs, ce});

        return ans;
    }
};