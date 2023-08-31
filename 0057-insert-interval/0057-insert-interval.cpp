class Solution {
public:
    #include <vector>
    #include <algorithm>

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        int cs = intervals[0][0];
        int ce = intervals[0][1];
        vector<vector<int>> ans;
        for(int i=0; i<intervals.size()-1; i++){
            if(ce >= intervals[i+1][0]){
                cs = min(cs, intervals[i+1][0]);
                ce = max(ce, intervals[i+1][1]);
            }else{
                ans.push_back({cs,ce});
                cs = intervals[i+1][0];
                ce = intervals[i+1][1];
            }
        }
        ans.push_back({cs,ce});
        
        return ans;
    }
};