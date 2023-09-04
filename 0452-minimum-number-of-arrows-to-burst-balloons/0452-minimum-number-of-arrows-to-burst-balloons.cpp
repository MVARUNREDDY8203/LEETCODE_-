class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        for(int i=0; i<points.size(); i++){
            swap(points[i][0], points[i][1]);
            cout<<"["<<points[i][0]<<","<<points[i][1]<<"] ";
        }
        sort(points.begin(), points.end());
        // sort(points.begin(), points.end(), [](vector<int> o1, vector<int> o2){
        //     return o1[1] < o2[1];
        // });
        int arrows = 1;
        int ce = points[0][0];
        
        for(int i=0; i<points.size(); i++){
            if(points[i][1] > ce){
                arrows++;
                ce = points[i][0];
            }
        }
        return arrows;
    }
};