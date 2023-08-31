class Solution {
public:
    #include <vector>
    #include <algorithm>
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        int i = 0, n = intervals.size();
        vector<vector<int>> ans;

        //case 1: non overlapping intervals before the merging intervals
        while(i<n && intervals[i][1] < newInterval[0]) ans.push_back(intervals[i++]);

        //case 2: merging intervals 
        while(i<n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        //case 3: non overlapping intervals after the merging intervals
        while(i<n) ans.push_back(intervals[i++]);

        return ans;
    }
};
    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //     intervals.push_back(newInterval);
    //     sort(intervals.begin(), intervals.end());

    //     int cs = intervals[0][0];
    //     int ce = intervals[0][1];
    //     vector<vector<int>> ans;
    //     for(int i=0; i<intervals.size()-1; i++){
    //         if(ce >= intervals[i+1][0]){
    //             cs = min(cs, intervals[i+1][0]);
    //             ce = max(ce, intervals[i+1][1]);
    //         }else{
    //             ans.push_back({cs,ce});
    //             cs = intervals[i+1][0];
    //             ce = intervals[i+1][1];
    //         }
    //     }
    //     ans.push_back({cs,ce});
        
    //     return ans;
    // }