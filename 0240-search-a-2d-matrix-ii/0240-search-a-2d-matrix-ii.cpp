class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        while (j >= 0 && i < m) {
            if (target == matrix[i][j]) return true;
            else if (target > matrix[i][j]) i++; // ans not in curr row cos row is sorted
            else j--; // ans ant be in the col cos col is sorted
        }   
        return false;
    }
};

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
//         for (int i=0; i<m; i++) {
//             int idx = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
//             if (idx < n && matrix[i][idx] == target) return true;
//         } 
//         return false;
//     }
// };