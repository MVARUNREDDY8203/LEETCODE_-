class NumMatrix {
private:
vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int m = matrix.size();
        int n = matrix[0].size();
        sum.resize(m, vector<int>(n, 0));

        for (int i=0; i<m; i++) {
            int prev = 0;
            for (int j=0; j<n; j++) {
                sum[i][j] = prev + matrix[i][j];
                prev = sum[i][j];
            }
        }
        for (int i=1; i<m; i++) {
            for (int j=0; j<n; j++) {
                int prev = sum[i-1][j];
                sum[i][j] += prev;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = sum[row2][col2];

        if (col1 != 0) {
            ans -= sum[row2][col1-1];
        }
        if (row1 != 0) {
            ans -= sum[row1-1][col2];
        }
        if (row1 != 0 && col1 != 0) {
            ans += sum[row1-1][col1-1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */