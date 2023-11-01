class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        for (int i=0; i<m; i++) {
            int idx = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
            if (idx < n && matrix[i][idx] == target) return true;
        } 
        return false;
    }
};