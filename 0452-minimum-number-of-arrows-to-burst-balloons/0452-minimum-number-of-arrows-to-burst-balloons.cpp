class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int arrows = 1;
        int ce = points[0][1];

        for(int i=0; i<points.size(); i++){
            if(points[i][0] > ce){
                arrows++;
                ce = points[i][1];
            }
            ce = min(points[i][1], ce);
        }
        
        return arrows;
    }
};