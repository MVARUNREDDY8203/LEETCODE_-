class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> o1, vector<int> o2){
            return o1[1] < o2[1];
        });
        int arrows = 1;
        int ce = points[0][1];
        
        for(int i=0; i<points.size(); i++){
            if(points[i][0] > ce){
                arrows++;
                ce = points[i][1];
            }
        }
        return arrows;
    }
};