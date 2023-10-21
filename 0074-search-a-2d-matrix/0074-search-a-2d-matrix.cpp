class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        
        vector<int> zero_mat(m);
        for (int i=0; i<m; i++) {
            zero_mat[i] = matrix[i][0];
        }

        int i = upper_bound(zero_mat.begin(), zero_mat.end(), target) - zero_mat.begin();
        i--;
        if (matrix[i][0] == target) return true;

        int j = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
        cout<<i<<" "<<j;
        if (j >= n) return false;
        if (matrix[i][j] == target) return true;
        return false;
    }
};

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();

//         int i = m-1;
//         int j = 0;
//         bool ans = false;
//         while (i >= 0) {
//             if (matrix[i][j] <= target) break;
//             i--;
//         }
//         while ()
//     }
// };